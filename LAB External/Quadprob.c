#include<stdio.h>
#define s 11
int hashvalue[s];
void init(void){
    for(int i = 0; i<s; i++)
    {
        hashvalue[i]=-1;
    }
    return;
}
int hashfunction(int key)
{
    return (key % s);
}
void insert(int key)
{
    int index = hashfunction(key);
    int i = 0;
    while(i < s)
    {
        if(hashvalue[(index + i*i) % s] == -1)
        {
            printf("\n%d element is inserted",key);
            hashvalue[(index + i*i) % s] = key;
            return;
        }
        //printf("\nThe collision occured");
        i++;
    }
    printf("\nThe hashtable is full can not insert element");
    return;
}
int search(int val){
    int index = hashfunction(val);
    int i =0;
    while(i<s)
    {
        if(hashvalue[(index+i*i)%s]==val)
        {
            printf("\nthe element found at %d",(index+i*i)%s);
            return (index+i*i)%s;
        }
            i++;
    }
    printf("\nthe element is not found");
    return -1;
}
void delete(int val)
{
    int pos = search(val);
    if(hashvalue[pos]== val);
    {
        printf(" and %d element is deleted",hashvalue[pos] );
        hashvalue[pos] = -1;
        return;
    }
}
void display()
{
    for(int i = 0 ; i < s ; i++)
    {
        printf("\n[%d]= %d", i, hashvalue[i]);
    }
}
int main()
{
    printf("\n-1 = Empty");
    init();
    insert(10);
    insert(20);
    insert(25);
    insert(35);
    printf("\nThe elements are:");
    display();
    search(20);
    delete(25);
    return 0;
}