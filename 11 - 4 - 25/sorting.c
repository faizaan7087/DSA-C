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
    printf("Insertion sort \n");
    for(int i = 0 ; i<n ; i++)
        {

            printf("%d ",a[i]);
        }
}

void bubblesort(int a[], int n)
{

    int temp = 0;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<i-n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;

            }

        }

    }
    printf("\nBubble sort \n");
   for(int i = 0 ; i<n ; i++)
        {

            printf("%d ",a[i]);
        }
}
void selectionsort(int a[], int n)
{
    int temp=0;
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1 ; j<n ; j++)
        {
            if(a[j] < a[min])
            {

            min = j;
            }

        }
        if( i!= a[min])
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;

        }
    }
    printf("\nSelection sort \n");
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
    bubblesort( a , n);
    selectionsort( a , n);

}
