#include <stdio.h>
#define SIZE 10
int top = -1;
int ar[SIZE];


void push(int x)
{
    if(top == SIZE-1)
    {
        printf("stack is full\n");

    }
    top++;
    ar[top] = x;

}
void prints()
{
    int pr=top;
    if(top == -1)
    {

        printf("the stack is empty\n");
        return;
    }

    while(pr != -1)
    {

        printf("%d\n",ar[pr]);
        pr--;

    }


}
void pop()
{
    if(top == -1)
    {

        printf("the stack is empty\n");
        return;
    }
    printf("the element %d deleted\n",ar[top]);
    top--;

}


void main()

{
    push(10);
    push(20);
    push(30);
    push(40);
    prints();
    pop();
    prints();

}
