#include <stdio.h>
int facto(int n)
{
    int i;
    int fac=1;
    for (i=1;i<=n;i++)
    {
        fac= fac*i;
    }
     printf(" %d",fac);
}
void main()
{


    int n;

    printf("Enter the number ");
    scanf("%d",&n);
    if ( n== 0 || n== 1)
    {

        printf( " factorial is 1");
    }
    else{
    printf("the factorial of number is");
    facto(n);
    }
}
