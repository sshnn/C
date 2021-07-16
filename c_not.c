#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

void sgets(char *p)
{ //boşlukları alır
    int c;
    while ((c = getchar()) != '\n')
        *p++ = c;
    *p = '\0';
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse_digit(int a[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        if (i == size - i)
            break;
        int temp = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = temp;
    }
}
void reverse_copy(char a[], int size)
{
    char dest[size];
    int i;
    int k = 0;
    for (i = 0; a[i] != '\0'; ++i)
        ;
    while (i != 0)
    {
        dest[k++] = a[--i];
    }
    dest[k] = '\0';
    printf("%s\n", dest);
    printf("%s\n", a);
}
void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%3d", a[i]);
    printf("\n");
}

void set_array_rand(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 21;
    }
}

void bubble_sort(int a[], int size) // O(n*n )
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void printArray(const int *p, int size)
{
    while (size--)
        printf("%3d ", *p++);
    printf("\n---------------------------------------------------------------\n");
}
void pArray(const int *p, const int *pend) // pArray(a,+a+SIZE);
{                                          //range...
    while (p != pend)
    {
        printf("%3d ", *p);
        ++p;
    }
    printf("\n");
}
void get_min_max(const int *p, int size, int *p_min, int *p_max) // 2 return
{
    *p_min = *p_max = *p; // p[0]
    for (int i = 1; i < size; i++)
    {
        if (p[i] > *p_max)
            *p_max = p[i];
        else if (p[i] < *p_min)
            *p_min = p[i];
    }
}
void copy_array(int *pdest, const int *psource, int n)
{
    while (n--)
    {
        *pdest++ = *psource++;
        //veya
        // *pdest=*psource;
        //++pdest;
        //++psoruce;
    }
}
void reverse_array(int *p_array, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(&p_array[i], &p_array[size - 1 - i]); // swap(p_array+i, p_array+size-1-i)
        //int temp=p_array[i];
        //p_array[i]=p_array[size-i-1];
        //p_array[size-i-1]=temp;
    }
}
void reverseArray(int *p, int size)
{
    int *pe = p + size; //dizinin bittiği adres
    while (p < pe)
    {                    //dizinin ilk adresi < son adresi
        swap(p++, --pe); //--pe=pe[SIZE-1] -> dizinin son elmanı
    }
}
void bsort(int *p, int size) //bubble sort
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (p[j] > p[j + 1])
                swap(p + j, p + j + 1);
        }
    }
}
void reverse_array_copy(int *pdest, const int *psource, int size)
{                    //diziyi ters çevirip diğer diziye kopyalar
    psource += size; // psource[size] dizinin bittiği adres
    while (size--)
    {
        *pdest++ = *--psource; // --psource= psource[size-1]
    }
}
int *get_array_max(const int *pa, size_t size)
{
    int *pmax = (int *)pa; //const cast
    for (size_t i = 1; i < size; i++)
    {
        if (pa[i] > *pmax)
        {
            pmax = (int *)(pa + i); //pmax=(int*)&pa[i]
        }
    }
    return pmax;
}
int *get_array_min(const int *pa, size_t size) // swap(get_array(a,SIZE),get_array_min(a,SIZE)); --> dizinin en büyük elemanı ile en kücüğü spaw
{
    int *pmin = (int *)pa; //const cast
    for (size_t i = 1; i < size; i++)
    {
        if (pa[i] < *pmin)
        {
            pmin = (int *)(pa + i); //pmin=(int*)&pa[i]
        }
    }
    return pmin;
}
void selection_sort(int *p, size_t size) // O(n^2)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        swap(get_array_min(p + i, size - 1), p + i); // get_array_min icinde for oldugundan O n kare
    }
}
int *search(const int *p, size_t size, int val) //aranan degerin adresinini dönürür
{
    while (size--)
    {
        if (p[size] == val) //*p==val ++p;
            return (int *)(p + size);
    }
    return NULL;
}
void myputs(const char *p) // puts()
{
    while (*p) //while(*p!='\0')
        putchar(*p++);
    putchar('\n');
}
void myputs2(const char *p)
{
    for (int i = 0; p[i] != '\0'; i++)
    {
        putchar(p[i]);
    }
    putchar('\n');
}
void reverse_puts(const char *p)
{
    for (int i = (int)strlen(p) - 1; i >= 0; --i)
        putchar(p[i]);
    putchar('\n');
}
size_t mystrlen(const char *p)
{
    const char *ps = p;
    while (*p)
        ++p;
    return p - ps; // son-ilk eleman adresi uzunluk döndürür
}
size_t mystrlen2(const char *p)
{
    size_t len;
    for (len = 0; p[len] != '\0'; ++len)
        ;
    return len;
}
int count_char(const char *p, int c) // istenilen char dan kac adet var //count_char(str,'a');
{
    int cnt = 0;
    while (*p)
    {
        if (*p++ == c)
            ++cnt;
    }
    return cnt;
}
int compare(const char *p, const char *psearch)
{
    while (*p && *psearch)
    {
        if (*p != *psearch)
            return 0;
        p++;
        psearch++;
    }
    return (*psearch == '\0'); //returns true if p==psearch
}
const char *mystrstr(const char *psource, const char *psearc)
{
    while (*psource)
    {
        if ((*psource == *psearc) && compare(psource, psearc))
            return psource;
        psource++;
    }
    return NULL;
}
char *mystrpbrk(const char *p, const char *pchars)
{
    while (*p)
    {
        if (strchr(pchars, *p) != NULL)
            return (char *)p;
        ++p;
    }
    return NULL;
}
char *str_reverse(char *p)
{
    char *pa = p; //ilk degeri döndürür (başka bir fonk da aynı adresi kullanılabilmesi icin)
    int len = strlen(p);
    int i = 0;
    int cnt = strlen(p) / 2;
    while (cnt--)
    {
        swap_char(&p[--len], &p[i++]);
        // char *temp=p[len-1];
        // p[len-1]=p[i];
        // p[i]=temp;
        // ++i;
        // --len;
    }
    return pa;
    // -----------------------------------------------
    // int size=strlen(p);
    // for(int i=size-1;i>=size/2;--i) {
    //     char * temp=p[i];
    //     p[i]=p[size-i-1];
    //     p[size-i-1]=temp;

    // }
    // return p;
}
char *my_strcat(char *p, const char *ps)
{
    //char *ptemp=p;
    //  while(*p)
    //      ++p;

    // while(*p++=*ps++)
    //     ;

    //-------------------------------------------
    char *ptemp = p;
    strcpy(p + strlen(p), ps); //p+strlen(p)='\0'
    // veya... strcpy(strchr(p,'\0'),ps);
    return ptemp;
}
int my_strcmp(const char *p1, const char *p2)
{
    while (*p1 == *p2)
    {
        if (*p1 == '\0')
            return 0;
        ++p1;
        ++p2;
    }
    return *p1 - *p2;
}
int is_at_end(const char *p1, const char *p2)
{
    size_t len_p1 = strlen(p1);
    size_t len_p2 = strlen(p2);

    if (len_p2 > len_p1)
        return 0;

    return !strcmp(p1 + len_p1 - len_p2, p2); //strcmp true ise 0 döner
}
void pswap(int **p1, int **p2)
{
    int *ptemp = *p1;
    *p1 = *p2;
    *p2 = ptemp;
}
void get_min_max2(const int *pa, int size, int **pmin, int **pmax) //pointer to pointer
{                                                                  //*pmin ile *pmaxa dizinin ilk adresi verildi
    *pmin = *pmax = (int *)pa;                                     //const cast(int*)

    for (int i = 1; i < size; ++i)
    {
        if (pa[i] < **pmin)
            *pmin = (int *)(pa + i);
        else if (pa[i] > **pmax)
            *pmax = (int *)(pa + i);
    }
    //test
    //int *pmax;
    // int *pmin;
    // get_min_max2(a,SIZE,&pmin,&pmax);
    // printf("en büyük: %d elamanın indisi %d en kücük: %d elamanın indisi %d",*pmax,pmax-a,*pmin,pmin-a);
}
void print_char_array(char *const *pa, int size)
{
    for (int i = 0; i < size; ++i) //wihle (size--) --> printf("%s ",*pa++);
        printf("%s ", pa[i]);
    printf("\n");
    //test
    //char *pname[]={"salih","arda","seda","samet"};
    // print_char_array(pname,4);
}
void print_int_array(int **pi, int size) //int array
{

    for (int i = 0; i < size; ++i)
        printf("%d ", **(pi + i));
    printf("\n");
    //test
    // int x = 10;
    // int b = 40;
    // int c = 15;
    // int *ba[] = {&x, &b, &c};
    // print_int_array(ba, 3);
}
void sort_char_array(char **pa, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(pa[j], pa[j + 1]) > 0)
            {
                char *temp = pa[j];
                pa[j] = pa[j + 1];
                pa[j + 1] = temp;
            }
        }
    }
}
void sort_int_array(int **p, int size) //?
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (*p[j] > *p[j + 1])
            {
                int *temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void gswap(void *vpx, void *vpy, int sz) //generic programming
{
    char *px = (char *)vpx;
    char *py = (char *)vpy;
    while (sz--)
    {
        char temp = *px;
        *px++ = *py;
        *py++ = temp;
    }
    //test
    // int x=29,y=77;
    // gswap(&x,&y,sizeof(int));
    // printf("x=%d   y=%d\n",x,y);
}
void *my_memset(void *vptr, int val, int size)
{
    char *p = (char *)vptr;

    while (size--)
        *p++ = (char)val;

    return vptr;
}
void *my_memcpy(void *vpdest, const void *vpsource, int n)
{
    char *pdest = (char *)vpdest;
    const char *psource = (const char *)vpsource;

    while (n--)
        *pdest++ = *psource++;

    return vpdest;
}
void *mymemchr(const void *vp, int val, int n)
{
    const char *p = (const char *)vp;

    while (n--)
    {
        if (*p == val)
            return (char *)p;
        ++p;
    }
    return NULL;
}
int my_memcmp(const void *vpx, const void *vpy, int n)
{
    const unsigned char *px = vpx;
    const unsigned char *py = vpy;

    while (n--)
    {
        if (*px != *py)
            return *px > *py ? 1 : -1;
        ++px;
        ++py;
    }
    return 0; // ikisi eşit
}
void *generic_reverse(void *vp, int size, int sz) //sz =sizeof(int/double..)
{
    char *p = (char *)vp;

    for (int i = 0; i < size / 2; ++i)
    {
        gswap(p + i * sz, p + (size - 1 - i) * sz, sz);
    }
}
void *generic_reverse_(void *vp, int size, int sz) //sz =sizeof(int/double..)
{
    char *pilk = (char *)vp;
    char *pson = pilk + (size - 1) * sz; //dizinin son eşemanının adresi

    while (pilk < pson)
    {
        gswap(pilk, pson, sz);
        pilk += sz;
        pson -= sz;
    }
}
void *generic_search(const void *vpa, int size, int sz, const void *vpkey)
{
    const char *p = (const char *)vpa;

    for (int i = 0; i < size; i++)
    {
        if (!memcmp(p + i * sz, vpkey, sz))
        {
            return (char *)(p + i * sz);
        }
    }
    return NULL;
    //test
    // int ival;
    // scanf("%d",&ival);
    // int *ptr=generic_search(a,SIZE,sizeof(int),&ival) ;
    // if(ptr){
    //     printf("bulundu dizinin [%d]. elemanı\n",ptr-a);
    // }
    // else
    // printf("bulunamadı");
}
void *generic_search_(const void *vpa, int size, int sz, const void *vpkey) //2.yöntem
{
    const char *p = (const char *)vpa;

    while (size--)
    {
        if (!memcmp(p, vpkey, sz))
            return (char *)p;
        p += sz; //bir sonraki eleman
    }
    return NULL;
}
void *fill_array(void *vp, int size, int sz, const void *vpal)
{
    char *p = (char *)vp;

    while (size--)
    {
        memcpy(p, vpal, sz);
        p += sz;
    }
    return vp;
}
void prints_chars(const char *fname, int (*fp)(int)) //parametresş ve geri dönüş degeri int
{                                                    //function pointers
    puts(fname);
    for (int i = 0; i < 128; ++i)
    {
        if (fp(i))
        {
            printf("%c", i);
        }
    }
    printf("\n\n");
    // test
    // printArray(a, SIZE);
    // prints_chars("isupper",&isupper);
    // prints_chars("islower",&islower);
    // prints_chars("isdigit",&isdigit);
}
int icmp(const void *vpx, const void *vpy)     //qsort 2 elemanın adresi ile
{                                              //void qsort(void* vpa, int size,int sz,int(*fp)(const void*,const void*))
    if (*(const int *)vpx > *(const int *)vpy) // *(const int*) vpx =const int *vpx //tür dönüsümü
        return 1;
    if (*(const int *)vpx > *(const int *)vpy)
        return -1;

    return 0;
}
int dcmp(const void *vpx, const void *vpy)
{
    double x = *(const double *)vpx;
    double y = *(const double *)vpy;

    return x > y ? 1 : x < y ? -1
                             : 0;
}
void generic_bsort(void *vpa, int size, int sz, int (*fp)(const void *, const void *))
{
    char *p = (char *)vpa;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (fp(p + j * sz, p + (j + 1) * sz) > 0)
            {
                gswap(p + j * sz, p + (j + 1) * sz, sz);
            }
        }
    }
    // test
    // generic_bsort(a,SIZE,sizeof(int),&icmp);
    // printArray(a, SIZE);
}
void generic_print(const void *vpa, int size, int sz, void (*fprint)(const void *))
{
    const char *p = vpa;
    while (size--)
    {
        fprint(p);
        p += sz;
    }
    printf("\n");
}
void iprint(const void *vp) //callback
{
    printf("%3d ", *(const int *)vp);
}
//{
//typedef int(*FTEST)(int);
//main
//         fonction pointers array
// FTEST fa[]={&islower,&isupper,&isalpha,&isdigit,&isspace};
// int ch;
// printf("bir karakter girin\n");
// ch=getchar();
// for(int i=0;i<sizeof(fa)/sizeof(fa[0]);++i) {
//     if(fa[i](ch)){
//         printf("OK!\n");
//     }
//     else{
//         printf("NOT OK!\n");
//     }
// }
//}
void set_random_20(int (*p)[20], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int k = 0; k < 20; ++k)
        {
            p[i][k] = rand() % 10;
        }
    }
}
void print_array_20(const int (*p)[20], int size)
{
    while (size--)
        //print_array(*p++, 20);
    

    printf("\n---------------------------------------------------------------\n");
    //test
    // int m[10][20];
    // set_random_20(m,10);
    // print_array_20(m,10);
}
void set_matrix(int *p, int row, int col)
{
    for(int i=0;i<row;++i) {
        for(int k=0;k<col;++k) {
            p[i*col+k]=rand()%10;
        }

    }
}
void print_matrix(int *p, int row, int col)
{
    for(int i=0;i<row;++i) {
        for(int k=0;k<col;++k) {
            printf("%d ",p[i*col+k]);
        }
        printf("\n");
    }
        printf("\n---------------------------------------------------------------\n");
}
void swap_str(char *px, char *py)
{
    char temp[20];
    strcpy(temp,px);
    strcpy(px,py);
    strcpy(py,temp);
    
}
void sort_names(char(*p)[20], int size)
{
    for(int i=0;i<size-1;++i){
        for(int k=0;k<size-1-i;++k){
            if(strcmp(p[k],p[k+1])>0){
                swap_str(p[k],p[k+1]);
            }
        }
    }
}
 
 int main(void)
{
    srand(time(NULL));
    int a[SIZE];
    set_array_rand(a, SIZE);
    printArray(a, SIZE);

     
    
}
