#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *insert_first(node *Head);
node *insert_last(node *Head);
node *insert_any_pos(node *Head);
node *display(node *Head);
node *insert_before(node *Head);
node *insert_after(node *Head);
node *delete_first(node *Head);
node *delete_last(node *Head);
node *delete_before(node *Head);
node *delete_after(node *Head);
node *delete_any_pos(node *Head);
node *delete_list(node *Head);
void reverse_display(node *Head);
node *delete_first_n_nodes(node *Head);
//node *delete_last_n _nodes(node *Head);
node *sort_list(node *Head);

int main()
{
    int option;
    node *Head = NULL;
    while(1)
    {
        printf("\n 1.Insert first.");
        printf("\n 2.Insert last.");
        printf("\n 3.Insert at any position.");
        printf("\n 4.Display");
        printf("\n 5.Insert before.");
        printf("\n 6.Insert after.");
        printf("\n 7.Delete first.");
        printf("\n 8.Delete last.");
        printf("\n 9.Delete before.");
        printf("\n 10.Delete after.");
        printf("\n 11. Delete any position.");
        printf("\n 12.Delete list.");
        printf("\n 13.Reverse display.");
        printf("\n 14.Delete first n nodes.");
        printf("\n 15.Delete last n nodes.");
        printf("\n 16.Sort the list.");
        printf("\n 17.Exit");
        printf("\n Enter your option:");
        scanf("%d", &option);
        switch(option)
        {
            case 1: Head = insert_first(Head);
            break;
            case 2: Head = insert_last(Head);
            break;
            case 3: Head = insert_any_pos(Head);
            break;
            case 4: printf("\n Display: ");
            Head = display(Head);
            break;
            case 5: Head = insert_before(Head);
            break;
            case 6: Head = insert_after(Head);
            break;
            case 7: Head = delete_first(Head);
            break;
            case 8: Head = delete_last(Head);
            break;
            case 9: Head = delete_before(Head);
            break;

            case 10: Head = delete_after(Head);
            break;
            case 11: Head = delete_any_pos(Head);

            break;

            case 12: Head = delete_list(Head);
            printf("\n Doubly linked list deleted.");

            break;

            case 13: printf("\n The list in revers eorder is:");
            reverse_display(Head);
            break;

            case 14: Head = delete_first_n_nodes(Head);
            break;
            //case 15: Head = delete_last_n_nodes(Head);
            // break;
            case 16: printf("\n The list after sorting is:");
            Head = sort_list(Head);
            Head = display(Head);
            break;

            case 17: exit(0);
            default: printf("\n Wrong input.");
        }
    }
    return 0;
}

node *insert_first(node *Head)
{
    int num;
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\n Enter the data you want to insert:");
    scanf("%d", &num);
    newnode->data = num;
    if(Head == NULL)
    {
        newnode->prev=NULL;
        newnode->next=NULL;
        Head = newnode;
    }
    else
    {
        newnode->prev = NULL;
        newnode->next = Head;
        Head->prev = newnode;
        Head = newnode;
    }
    return Head;
}

node *insert_last(node *Head)
{
    node *ptr, *newnode;
    int num;
    newnode = (node*)malloc(sizeof(node));
    printf("\n Enter the data you want to insert:");
    scanf("%d", &num);
    newnode->data = num;
    if(Head == NULL)
    {
        newnode->prev=NULL;
        newnode->next=NULL;
        Head = newnode;
    }
    else
    {
        ptr = Head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
        newnode->next = NULL;
    }
    return Head;
}

node *display(node *Head)
{
    node *ptr;
    ptr = Head;
    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return Head;
}

node *insert_any_pos(node *Head)
{
    node *newnode, *ptr, *p1;
    ptr = p1 = Head;
    int count,num,val, pos;
    count = num = 0;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\n Enter the position you want to insert:");
    scanf("%d", &pos);
    pos = pos-1;
    if((pos > count) || (pos < 0))
    {
        printf("\n Invalid input");
        return Head;
    }
    else if(pos == 0)
    {
        Head = insert_first(Head);
        return Head;
    }
    else
    {
        ptr = Head;
        p1 = ptr;
        while(num != pos)
        {
            num++;
            p1 = ptr;
            ptr = ptr->next;
            ptr->prev = p1;
            p1->next = ptr;
        }
        newnode = (node *)malloc(sizeof(node));
        printf("\n Enter the data you want to insert:");
        scanf("%d", &val);
        newnode->data = val;
        p1->next = newnode;
        newnode->prev = p1;
        newnode->next = ptr;
        ptr->prev = newnode;
        return Head;
    }
}

node *insert_before(node *Head)
{
    node *ptr, *newnode;
    int val, num;
    printf("\n Enter the value before which you want to insert:");
    scanf("%d", &val);
    if(Head == NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("\n Enter the data you want to insert:");
        scanf("%d", &num);
        newnode->prev = NULL;
        newnode->next = NULL;
        newnode->data = num;
        Head = newnode;
    }
    if(Head->data == val)
    {
        Head = insert_first(Head);
        return Head;
    }
    else
    {
        newnode = (node *)malloc(sizeof(node));
        printf("\n Enter the data you want to insert:");
        scanf("%d", &num);
        ptr = Head;
        while(ptr !=NULL)
        {
            if(ptr->data == val && ptr!= Head)
            {
                newnode->data = num;
                newnode->next = ptr;
                newnode->prev = ptr->prev;
                ptr->prev->next = newnode;
                ptr->prev = newnode;
                break;
            }
            ptr = ptr->next;
        }
        if(ptr == NULL)
        {
            printf("\n The search value %d is not found", val);
        }
    }
    return Head;
}

node *insert_after(node *Head)
{
    node *ptr, *newnode;
    int val, num;
    printf("\n Enter the value after which you want to insert:");
    scanf("%d", &val);
    if(Head == NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("\n Enter the data you want to insert:");
        scanf("%d", &num);
        newnode->prev = NULL;
        newnode->next = NULL;
        newnode->data = num;
        Head = newnode;
    }
    else
    {
        ptr = Head;
        while(ptr != NULL)
        {
            if(ptr->data == val && ptr->next != NULL)
            {
                newnode = (node *)malloc(sizeof(node));
                printf("\n Enter the data you want to insert:");
                scanf("%d", &num);
                newnode->data = num;
                newnode->prev = ptr;
                newnode->next = ptr->next;
                ptr->prev->prev = newnode;
                ptr->next = newnode;
                break;
            }
            if(ptr->data == val && ptr->next == NULL)
            {
                Head = insert_last(Head);
                break;
            }
            ptr = ptr->next;
        }
        if(ptr == NULL)
        {
            printf("\n The search value %d is not found", val);
        }
    }
    return Head;
}

node * delete_first(node *Head)
{
    node *ptr;
    if(Head == NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
        ptr = Head;
        Head = Head->next;
        Head->prev = NULL;
        free(ptr);
    }
    return Head;
}

node *delete_last(node *Head)
{
    node *ptr;
    if(Head == NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
        ptr = Head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
    return Head;
}

node *delete_before(node *Head)
{
    node *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to be deletd:");
    scanf("%d", &val);
    if(Head == NULL)
    {
        printf("\n The list is empty");
    }
    if(Head->data == val)
    {
        printf("\n No nodes present before it.");
    }
    else
    {
        ptr = Head;
        while(ptr != NULL)
        {
            if(ptr->data == val && ptr != Head)
            {
                temp = ptr->prev;
                if(temp == Head)
                {
                    Head = delete_first(Head);
                    break;
                }
                else
                {
                    ptr->prev = temp->prev;
                    temp->prev->next = ptr;
                    free(temp);
                    break;
                }
            }
            ptr = ptr->next;
        }
        if(ptr == NULL)
        {
            printf("\n Required value %d to be deleted not found.", val);
        }
    }
    return Head;
}

node *delete_after(node *Head)
{
    node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to be deletd:");
    scanf("%d", &val);
    if(Head == NULL)
    {
        printf("\n The list is empty");
    }
    ptr = Head;
    while(ptr != NULL)
    {
        if(ptr->data == val && ptr->next != NULL)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            free(temp);
            break;
        }
        if(ptr->data == val && ptr->next == NULL)
        {
            printf("\n No nodes present after it.");
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("\n Required value %d to be deleted not found.", val);
    }
    return Head;
}

node *delete_any_pos(node *Head)
{
    node *p1, *ptr;
    int count,num, pos;
    count = num = 0;
    ptr = p1 = Head;
    while(ptr!= NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\n Enter the position you want to delete:");
    scanf("%d", &pos);
    pos = pos-1;
    if((pos > count) || (pos < 0))
    {
        printf("\n Invalid input");
        return Head;
    }
    else if(pos == 0)
    {
        Head = delete_first(Head);
        return Head;
    }
    else
    {
        ptr = Head;
        p1 = ptr;
        while(num!= pos)
        {
            num++;
            p1 = ptr;
            ptr = ptr ->next;
            ptr->prev = p1;
            p1->next = ptr;
        }
        p1->next = ptr->next;
        ptr->next->prev = p1;
        free(ptr);
        return Head;
    }
}

node *delete_list(node *Head)
{
    while(Head != NULL)
    {
        Head = delete_first(Head);
    }
    return Head;
}

void reverse_display(node *Head)
{
    if(Head == NULL)
        return;
    reverse_display(Head->next);
    printf("%d\t", Head->data);
}

node *sort_list(node *Head)
{
    node *ptr1,*ptr2;
    int temp;
    ptr1 = Head;
    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2!= NULL)
        {
            if(ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return Head;
}

node *delete_first_n_nodes(node *Head)
{
    node *p1, *p2,*p3;
    int count=0, num;
    p1 = Head;
    printf("\n Enter the no.of nodes you want to delete from first:");
    scanf("%d", &num);
    while(count < num)
    {
        count++;
        p1 = p1->next;
    }
    p2 = Head;
    while(p2 != Head)
    {
        p3 = p2;
        p2 = p2->next;
        free(p3);
    }
    Head = p1;
    return Head;
}