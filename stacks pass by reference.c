#include <stdlib.h>
#include <stdio.h>
#define size 10
void push(int st[], int *top, int data)
{
    if (top == size - 1)
    {
        printf("overflow");
    }
    else
    {
        *top = *top + 1;
        st[*top] = data;
    }
}
int pop(int st[], int *top)
{
    if (*top == -1)
    {
        printf("underflow");
    }
    else
    {
        int data = st[*top];
        *top = *top - 1;
        return data;
    }
}
void display(int st[], int *top)
{
    if (*top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        for (int i = 0; i < *top; i++)
            printf("%d\n", st[i]);
    }
}
void main()
{
    int st[size], top, choice, data, del;
    top = -1;
    printf("enter choice");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("enter the data to be inserted");
        scanf("%d", &data);
        push(st, &top, data);
        break;
    case 2:
        del = pop(st, &top);
        printf("deleted item is %d", del);
        break;
    case 3:
        display(st, &top);
        break;
    }
}