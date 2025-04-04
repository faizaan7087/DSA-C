#include <stdio.h>
int facto(int n) {

    if (n == 0 || n == 1) {
        return 1;
    } else {

        return n * facto(n - 1);
    }
}
void main()
{


    int n;

    printf("Enter the number ");
    scanf("%d",&n);

    printf("the factorial of number is %d",facto(n));

}
