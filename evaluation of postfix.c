#include <stdio.h>
#include <stdlib.h>
#define size 5
int stack[size], item, top = -1;
void push(int item)
{
    if (top == size - 1)
        printf("Stack is full");
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
int pop()
{
    int ele;
    if (top == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        ele = stack[top];
        top--;
        return ele;
    }
}
void main()
{
    char postfix[20], ele;
    int n1, n2, res, final;
    printf("Enter the postfix expression");
    scanf("%c", postfix);
    for (int i = 0; i < strlen(postfix); i++)
    {
        ele = postfix[i];
        if (isdigit(ele))
            push(ele);
        else
        {
            n2 = pop();
            n1 = pop();
            switch (ele)
            {
            case '+':
                res = n1 + n2;
                break;
            case '-':
                res = n1 - n2;
                break;
            case '*':
                res = n1 * n2;
                break;
            case '/':
                res = n1 / n2;
                break;
            }
            push(res);
        }
    }
    final = pop();

    printf("Result is %d", final);
}
