#include <stdio.h>
#include <stdlib.h>
#define size 20
int queue[size], front = -1, rear = -1;
void enqueue(int ele)
{
    if (rear == size - 1)
        printf("Queue is full");
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        queue[rear] = ele;
    }
    else
    {
        queue[rear++] = ele; 
    }
}
void dequeue()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue is empty");
    }
    else if (rear == front)
    {

        printf("Removed element is %d", queue[front]);
        rear = front = -1;
    }
    else
    {
        printf("Removed element is %d", queue[front]);
        front++;
    }
}
void traverse()
{
    for (int i = front; i <= rear; i++)
        printf("\n %d", queue[i]);
}
void main()
{
    int choice, ele;
    while (1)
    {
        printf("Enter your choice");
        printf("/n1.insert/n 2.delete/n 3.traverse");
        scanf("%d", choice);
        switch (choice)
        {
        case 1:
            printf("enter element");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        }
    }
}