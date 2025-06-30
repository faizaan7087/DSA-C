#include<stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j = low ; j<high ; j++)
    {
        if(arr[j] < pivot)                                                                  
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high)
{
    
    if(low < high)
    {
        int pi = partition(arr,low,high);

        quicksort(arr, low , pi - 1 );
        quicksort(arr, pi +1 , high );
    }
    
}
void display(int arr[], int n)
{
    printf("The array is : ");
    for(int i = 0; i<n ; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[]={24,9,29,14,19,27};
    int n = sizeof(arr)/sizeof(int);
    printf("Before sort:\n");
    display(arr, n);
    quicksort(arr , 0 , n-1);
    printf("\nAfter sort:\n");
    display(arr, n);
}