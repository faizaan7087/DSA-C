#include<stdio.h>
#define size 10
int a[size];
int top = -1;
void push(int n)
{
    if(top == size-1)
    {
        printf("\n the stack is full");
        return;
    }
    printf("\n the %d element is pushed", n);
    top++;
    a[top]=n;
}
void pop()
{
    if(top == -1)
    {
        printf("\n the stack is Empty");
        return;
    }
    printf("\n the %d element is popped", a[top]);
    top--;
}
void print()
{
    int temp=top;
    if(top == -1)
    {
        printf("\n the stack is Empty");
        return;
    }
    printf("\nthe stack contains:");
    while(temp!=-1)
    {
        printf("\n%d\n",a[temp]);
        temp--;
    }
}
void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(10);
    push(60);
    print();
    pop();
    pop();
    pop();
    pop();
    print();
}