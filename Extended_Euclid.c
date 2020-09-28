#include <stdio.h>
#include <stdlib.h>

int * Extended_Euclid(int , int);
int main()
{
    int gcd[2],*Bezout;
    printf("Please input gcd\n");
    scanf("%d %d",gcd,gcd+1);
    Bezout=Extended_Euclid(gcd[0],gcd[1]);
    printf("%d=gcd(%d,%d)=%d*(%d)+%d*(%d)",Bezout[0],gcd[0],gcd[1],gcd[0],Bezout[1],gcd[1],Bezout[2]);
    return 0;
}
int * Extended_Euclid(int a,int b)
{
    int *b_0=(int *)malloc(sizeof(int)*3);
    if(b==0)
    {
        b_0[0]=a;
        b_0[1]=1;
        b_0[2]=0;
        return b_0;
    }
    else
    {
        int *b_1=Extended_Euclid(b,a%b);
        b_0[0]=b_1[0];
        b_0[1]=b_1[2];
        b_0[2]=b_1[1]-(a/b)*b_1[2];
        return b_0;
    }
}
