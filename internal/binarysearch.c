#include <stdio.h>
void binarysearch(int a[], int n, int target)
{
    int left = 0, right =n-1;
    while(left <= right)
    {
        int mid = (left+right)/2;
        if(a[mid]>target)
        {
            right = mid-1;
        }
        else if(a[mid]<target)
        {
            left = mid+1;
        }
        else{
            printf("the element is found at %d",mid);
            return;
        }
    }
    printf("the element not found");
}
int main()
{
    int a[10]={1,3,4,5,6,7,9,10,11,22};
    int n = sizeof(a)/sizeof(int);
    int target = 9;
    binarysearch(a, n, target);
}