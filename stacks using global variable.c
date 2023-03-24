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
void pop()
{
    int ele;
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        ele = stack[top];
        top--;
        printf("Popped element is %d", ele);
    }
}
void display()
{
    if (top == -1)
        printf("Stack is empty");
    else
    {
        for (int i = 0; i < top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}
void main()
{
    int choice;
    while (1)
    {
        printf("enter your choice\n 1.Push\n 2.Pop\n 3.Display\n 4. exit ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid number");
            break;
        }
    }
}