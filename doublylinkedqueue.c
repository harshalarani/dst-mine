#include <stdio.h>
#include <stdlib.h>
#define N 10
int queue[N], left = -1, right = -1;
void insertleft(int item)
{
    if (left == 0 && right == N - 1 || left == right + 1)
        printf("full");
    else if (left == -1)
    {
        right = left = 0;
        queue[left] = item;
    }
    else
    {
        if (left == 0)
            left = N - 1;
        else
            left = left - 1;
        queue[left] = item;
    }
}
void insertright(int item)
{
    if (left == 0 && right == N - 1 || left == right + 1)
        printf("full");
    else if (left == -1)
    {
        right = left = 0;
        queue[right] = item;
    }
    else
    {
        if (right == N - 1)
            right = 0;
        else
            right = right + 1;
        queue[right] = item;
    }
}
int deleteleft()
{
    int item;
    if (left == -1)
    {
        printf("empty");
        return -1;
    }
    else if (left == right)
    {
        item = queue[left];
        left = right = -1;
        return item;
    }
    else
    {
        if (left == N - 1)
            left = 0;
        else
            left = left + 1;
        item = queue[left];
        return item;
    }
}
int deleteright()
{
    int item;
    if (right == -1)
    {
        printf("empty");
        return -1;
    }
    else if (left == right)
    {
        item = queue[right];
        left = right = -1;
        return item;
    }
    else
    {
        if (right == 0)
            right = N - 1;
        else
            right = right - 1;
        item = queue[right];
        return item;
    }
}
void traverse()
{
    int i = left;
    while (i <= right)
    {
        printf("%d/n", queue[i]);
        i = (i + 1) % N;
    }
}

void main()
{
    int choice, ele;
    while (1)
    {
        printf("Enter your choice");
        printf("/n1.insert left/n 2.insert right 3.delete left 4.delete right/n 3.traverse");
        scanf("%d", choice);
        switch (choice)
        {
        case 1:
            printf("enter element");
            scanf("%d", &ele);
            insertleft(ele);
            break;
        case 2:
            printf("enter element");
            scanf("%d", &ele);
            insertright(ele);
            break;
        case 3:
            deleteleft();
            break;
        case 4:
            deleteright();
            break;
        case 5:
            traverse();
            break;
        }
    }
}