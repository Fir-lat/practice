//计算阶乘的素因子分解式
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime(int, int *, int *);
int main()
{
    int n,i,j;
    printf("Please input the integer you want.\n");
    scanf("%d", &n);
    int *factorization,*p;
    factorization=(int*)malloc(n*sizeof(int));
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        p[i]=1;
        factorization[i]=0;
    }
    for(i=2;i<=sqrt(n);i++)
    {
        for(j=2;i*j<=n;j++)
        {
            p[i*j-1]=0;
        }
    }
    p[0]=0;
    for(i=1;i<=n;i++)
    {
        prime(i,factorization,p);
    }
    printf("So the result is:\n");
    for(i=0;i<n;i++)
    {
        if(*(factorization+i))  printf("%d^(%d)",i+1,*(factorization+i));
    }
    free(factorization);
    free(p);
    return 0;
}
void prime(int x,int *fac,int *p)
{
    int i=1;
    while(i<x)
    {
        if(*(p+i) &&  !(x % (i+1)))
        {
            x /= (i+1);
            (*(fac+i))++;
        }
        else i++;
    }
}
