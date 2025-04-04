#include <stdio.h>

#define SIZE 5
int eflag,dflag, a[SIZE];
void enque(int element)
{
    if( eflag < SIZE-1)
    {
        eflag++;
        a[eflag]=element;
          printf("\nthe %d element is enqued", element);

    }
    else
    {

    printf("\n The queue is full");
    }
}
    int dque()
{
    int element;
    if ( dflag != eflag)
    {
        dflag++;
        element = a[dflag];

    }
    else
    {

    printf("the queue is empty");
    }
}
    int main()
    {

        eflag = dflag = -1;
        enque(10);
        enque(20);
        enque(30);
        enque(40);
        enque(50);
        enque(60);


        printf("\n%d\n", dque());
        printf("%d\n", dque());
        printf("%d\n", dque());
        printf("%d\n", dque());
        printf("%d\n", dque());
           return 0;

    }


