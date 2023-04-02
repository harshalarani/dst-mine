#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *ptr)
{
    if (ptr == 0)
        printf("List empty");
    else
    {
        while (ptr != 0)
        {
            printf("/n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}
void main()
{
    struct node *head, *temp, *nextnode;
    head = 0;
    int i = 0;
    int n;
    printf("Enter the number of nodes");
    scanf("%d", &n);
    nextnode = (struct node *)malloc(sizeof(struct node));
    printf("Eneter the element to be inserted ");
    scanf("%d", &nextnode->data);
    nextnode->next = 0;
    while (i < n)
    {
        if (head == 0)
        {
            head = temp = nextnode;
        }
        else
        {
            temp->next = nextnode;
            temp = nextnode;
        }
    }
    traverse(head);
}
