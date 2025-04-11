#include <stdio.h>
void insertionsort(int a[],int n)
{

    int temp = 0;
    for(int i = 1; i <n ; i++)
    {
        int cur = a[i];
        int prev = i-1;
        while(prev >= 0 && a[prev] > cur)
        {
            temp = a[prev];
            a[prev] = a[prev + 1];
            a[prev + 1] = temp;
            prev--;
        }
        a[prev + 1] = cur;

    }
    for(int i = 0 ; i<n ; i++)
        {

            printf("%d ",a[i]);
        }
}
void main()
{

    int a[]={5 , 4, 3 , 2, 1};
    int n = sizeof(a)/sizeof(int);
    insertionsort(a , n);

}
