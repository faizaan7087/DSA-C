#include <stdio.h>

int stack[100];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char expr[]) {
    int i = 0;
    char ch;
    int a, b, result;

    while (expr[i] != '\0') {
        ch = expr[i];

        if (ch >= '0' && ch <= '9') {
            push(ch - '0');  // convert char to int
        } else {
            b = pop();
            a = pop();

            if (ch == '+') result = a + b;
            else if (ch == '-') result = a - b;
            else if (ch == '*') result = a * b;
            else if (ch == '/') result = a / b;

            push(result);
        }

        i++;
    }

    return pop();  // final result
}

int main() {
    char expr[] = "53+82-*"; // Postfix expression: (5 + 3) * (8 - 2)
    int result = evaluatePostfix(expr);
    printf("Result = %d\n", result);
    return 0;
}