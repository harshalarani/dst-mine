#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 30
char stack[size], top = -1;
char infix[size], postfix[size];
void push(char sym)
{
    top++;
    stack[top] = sym;
}
char pop()
{
    char item;
    item = stack[top];
    top--;
    return item;
}

int pre(char s)
{
    if (s == '^')
        return 3;
    else if (s == '*' || s == '/')
        return 2;
    else if (s == '+' || s == '-')
        return 1;
    else
        return 0;
}

void main()
{
    char ele, elem;
    int k = 0;
    printf("Enter the infix expression");
    scanf("%s", infix);
    push('#');
    for (int i = 0; i < strlen(infix); i++)
    {
        ele = infix[i];
        if (ele == '(')
            push(ele);
        else if (isalnum(ele))
            postfix[k++] = ele;
        else if (ele == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        }
        else
        {
            while (pre(stack[top] >= pre(ele)))
                postfix[k++] = pop();
            push(ele);
        }
    }
    while (stack[top] != '#')
        postfix[k++] = pop();
    printf("the p exp is %s", postfix);
}