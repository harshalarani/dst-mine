#include <stdio.h>
#include <stdlib.h>
#define size 20
int queue[size], front = -1, rear = -1;
void enqueue(int ele)
{
    if ((rear + 1) % size == front)
        printf("Queue is full");
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        queue[rear] = ele;
    }
    else
    {
        queue[(rear + 1) % size] = ele;
    }
}
void dequeue()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue is empty");
    }

    else
    {
        printf("Removed element is %d", queue[front]);
        front = (front + 1) % size;
    }
}
void traverse()
{
    int i = front;
    while (i != rear + 1)
    {
        printf("\n %d", queue[i]);
        i = (i + 1) % size;
    }
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