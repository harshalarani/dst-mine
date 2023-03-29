#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 30
char stack[size], top = -1;
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
void main()
{
    char exp[20], reverse[20];
    printf("ENter");
    scanf("%s", exp);
    for (int i = 0; i < strlen(exp); i++)
    {
        push(exp[i]);
    }
    for (int i = 0; i < top; i++)
    {
        reverse[i] = pop();
    }

    printf(reverse);
}