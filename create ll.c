struct node
{
    int data;
    struct node *next;
};
 void transverse(struct node *head)
{
    if (head == 0)
        printf("List is empty");
    
    else
    {
        struct node*ptr=head;
        while(ptr!=0){
        printf("%d",ptr->data);
        ptr = ptr->next;}
    }
}
void main()
{
    struct node *temp, *newnode, *head;
    head = 0;
    int n, i;
    i = 0;
    printf("Enter the no of nodes");
    scanf("%d", &n);
    while (i < n)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data to be inserted");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
    }
    transverse(head);
}
