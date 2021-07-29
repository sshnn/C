#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRIVATE static
#define PUBLIC
#define YEARBASE 1900
#define RANDOM_YEAR_MIN 1940
#define RANDOM_YEAR_MAX 2021

#define isleap(y) ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define mon_days(y, m) (daytabs[isleap(y)][m])

PRIVATE const int daytabs[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};
PRIVATE const char *const pmons[] = {
    "",
    "Ocak",
    "Subat",
    "Mart",
    "Nisan",
    "Mayis",
    "Haziran",
    "Temmuz",
    "Agustos",
    "Eylul",
    "Ekim",
    "Kasim",
    "Aralik"};

PRIVATE const char *const pdays[] = {
    "Pazar",
    "Pazartesi",
    "Sali",
    "Carsamba",
    "Persembe",
    "Cuma",
    "Cumartesi",
};

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PRIVATE int is_valid_date(int d, int m, int y);
PRIVATE Date *set(Date *p, int d, int m, int y);
PRIVATE int day_of_week(int d, int m, int y);
PRIVATE int totaldays(const Date *p);
PRIVATE Date *to_date(Date *p, int tdays);

//public functions

PUBLIC void print_date(const Date *p)
{
    printf("%02d %s %d %s\n", p->d, pmons[p->m], p->y, pdays[get_week_day(p)]);
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *set_date(Date *p, int d, int m, int y)
{
    return set(p, d, m, y);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *set_date_today(Date *p)
{
    time_t timer;
    time(&timer);
    struct tm *tptr = localtime(&timer);
    return set(p, tptr->tm_mday, tptr->tm_mon + 1, tptr->tm_year + 1900);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *set_date_str(Date *p, const char *pstr)
{
    return set(p, atoi(pstr), atoi(pstr + 3), atoi(pstr + 6));
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *set_date_random(Date *p)
{
    int y = rand() % (RANDOM_YEAR_MAX - RANDOM_YEAR_MIN + 1) + RANDOM_YEAR_MIN;
    int m = rand() % 12 + 1;
    int d = rand() % mon_days(y, m) + 1;

    return set(p, d, m, y);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *set_month_day(Date *p, int mday)
{
    return set(p, mday, p->m, p->y);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *set_month(Date *p, int mon)
{
    return set(p, p->d, mon, p->y);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *set_year(Date *p, int year)
{
    return set(p, p->d, p->m, year);
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------



PUBLIC Date *scan_date(Date *p)
{
    int d, m, y;
    int retval = scanf("%d%d%d", &d, &m, &y);
    if(retval!=3) {
        fprintf(stderr,"Giris islemi hatali...");
        exit(EXIT_FAILURE);
    }
    return set(p, d, m, y );
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC int cmp_date(const Date *pa, const Date *pb)
{
    if(pa->y != pb->y)
        return pa->y - pb->y;
    
    if(pa->m != pb->m) 
        return pa->m - pb->m;

    return pa->d - pb->d;
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC int get_year(const Date *p)
{
    return p->y;
}
PUBLIC int get_month(const Date *p)
{
    return p->m;
}
PUBLIC int get_month_day(const Date *p)
{
    return p->d;
}

PUBLIC int get_year_day(const Date *p)
{
    int sum=p->d;

    for (int i = 1; i < p->m; i++)
        sum += mon_days(p->y, i);
    
    return sum;
}
PUBLIC int get_week_day(const Date *p)
{
    day_of_week(p->d, p->m, p->y);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC int date_diff(const Date *p1, const Date *p2)
{
    return abs(totaldays(p1) - totaldays(p2));
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PUBLIC Date *ndays_date(Date* pdest, const Date* psource, int n)
{
    return to_date(pdest, totaldays(psource) + n);
}







//private functions
PRIVATE int is_valid_date(int d, int m, int y)
{
    return y >= YEARBASE && m > 0 && m <= 12 && d > 0 && d <= mon_days(y, m);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PRIVATE Date *set(Date *p, int d, int m, int y)
{
    if (!is_valid_date(d, m, y))
    {
        fprintf(stderr, "gecersiz tarih olustu\n");
        exit(EXIT_FAILURE);
    }
    p->d = d;
    p->m = m;
    p->y = y;
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PRIVATE int day_of_week(int d, int m, int y)
{
    return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PRIVATE int totaldays(const Date *p)
{
    int sum=get_year_day(p);

    for(int i= YEARBASE; i< p->y; ++i) {
        sum += isleap(i) ? 366 : 365;
    }
    return sum;
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

PRIVATE Date *to_date(Date *p, int tdays)
{
    int y = YEARBASE;

    while (tdays > (isleap(y) ? 366:365)) {
        tdays -= isleap(y) ? 366:365;
        ++y;
    }

    int m=1;

    while (tdays > mon_days(y,m)) {
        tdays -=mon_days(y, m);
        ++m;
    }
    int d =tdays;

    return set(p, d, m, y);
}
