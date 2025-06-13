#include<stdio.h>
void merge(int a[], int left, int mid, int right)
{
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1], R[n1];
    for(i=0; i<n1; i++)
    {
        L[i]=a[left+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j]=a[mid+j+1];
    }
    i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k++]=L[i++];
        }
        else{
            a[k++]=R[j++];
        }
        
    }
        while(i<n1){ a[k++]=L[i++];}
        while(j<n2){ a[k++]=R[j++];}
}
void mergesort(int a[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left+right)/2;
    mergesort(a, left, mid);
    mergesort(a, mid+1, right);
    merge(a,left,mid,right);
}
void print(int a[],int n){
    printf("The elements are :\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }

}
int main()
{
    int a[]= {1,2,6,4,3,9,0,4};
    int n = sizeof(a)/sizeof(int);
    print(a, n);
    mergesort(a, 0, n-1);
    print(a, n);
}