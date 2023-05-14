#include <stdio.h>
#include <stdlib.h>
#define size 20
char stack[size], top = -1;
int match(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '(' && b == ')')
        return 1;
    else
        return 0;
}
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
int checkk(char exp[])
{
    char temp;
    for (int i = 0; i < strlen(exp); i++)
    {
        char ele = exp[i];
        if (ele == '[' || ele == '(' || ele == '{')
            push(ele);
        else if (ele == ']' || ele == ')' || ele == '}')
            if (top == -1)
                // Right more than left
                return 0;
        temp=pop();
            else if (!match(temp, ele))
                // mismatched
                return 0;
    }
    if (top == -1)
        return 1;
    else
        return 0; // Left more than right
}
void main()
{
    int valid;
    char exp[30];
    printf("enter the expression");
    scanf("%s", exp);
    valid = checkk(exp);
    if (valid == 1)
    {
        printf("balanced paranthesis");
    }
    else
    {
        printf("Unbalnced paranthesis");
    }
}
