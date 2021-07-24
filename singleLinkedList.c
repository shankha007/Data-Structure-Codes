#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*Structure Declaration*/
typedef struct SLL //Here typedef is used to rename struct SLL
{
    int data;
    struct SLL *next;
} node;

/*Prototype Declaration*/
node *insert_first(node *);
node *display(node *);
node *insert_last(node *);
node *delete_first(node *);
node *delete_last(node *);
node *insert_after_value(node *);
node *insert_before_value(node *H);
node *insert_after_position(node *H);
node *insert_before_position(node *H);
node *delete_after_value(node *H);
node *delete_before_value(node *H);
node *delete_position(node *H);
void reverse_display(node *H);
node *physically_reverse_display(node *H);
node *free_all_nodes(node *H);
node *node_count(node *H);
node *del_first_n_nodes(node *H);
node *del_last_n_nodes(node *H);

/*Main Function*/
void main()
{
    node *H=NULL;// As initially there exists no node
    int c; // for user choice
    while(1)// it creates an infinite loop
    {
        //---------MENU---------
        printf("\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Delete First");
        printf("\n4. Delete Last");
        printf("\n5. Insert After a Value");
        printf("\n6. Insert Before a Value");
        printf("\n7. Insert After Position");
        printf("\n8. Insert Before Position");
        printf("\n9. Delete After a Value");
        printf("\n10. Delete Before Value");
        printf("\n11. Delete Position");
        printf("\n12. Display");
        printf("\n13. Reverse Display");
        printf("\n14. Physically Reverse Display");
        printf("\n15. Free All Nodes");
        printf("\n16. Node Count");
        printf("\n17. Delete First nth Nodes");
        printf("\n18. Delete Last nth Nodes");
        printf("\n19. Exit");
        printf("\nEnter Your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("\nInserting First Operation:");
            H=insert_first(H);
            break;
            case 2:printf("\nInserting Last Operation:");
            H=insert_last(H);
            break;
            case 3:printf("\nDeleting First Operation:");
            H=delete_first(H);
            break;
            case 4:printf("\nDeleting Last Operation:");
            H=delete_last(H);
            break;
            case 5:printf("\nInserting After a Value:");
            H=insert_after_value(H);
            break;
            case 6:printf("\nInserting Before a Value:");
            H=insert_before_value(H);
            break;
            case 7:printf("\nInserting After position:");
            H=insert_after_position(H);
            break;
            case 8:printf("\nInserting Before position:");
            H=insert_before_position(H);
            break;
            case 9:printf("\nDeleting After Value:");
            H=delete_after_value(H);
            break;
            case 10:printf("\nDeleting Before Value:");
            H=delete_before_value(H);
            break;
            case 11:printf("\nDelete a Position:");
            H=delete_position(H);
            break;
            case 12:printf("\nDisplay:\n");
            H=display(H);
            break;
            case 13:printf("\nReverse Display:\n");
            reverse_display(H);
            break;
            case 14:H=physically_reverse_display(H);
            printf("\nList is Reversed.");
            break;
            case 15:H=free_all_nodes(H);
            printf("\nNow, The list is empty.");
            break;
            case 16:printf("\nNodes are being counted.");
            H=node_count(H);
            break;
            case 17:printf("\nDeleting First Multiple Nodes:");
            H=del_first_n_nodes(H);
            break;
            case 18:printf("\nDeleting Last Multiple Nodes:");
            H=del_last_n_nodes(H);
            break;
            case 19:printf("\nThe End..\n");
            exit(0);

            default:printf("Invalid Input");
        }//end of switch
    }//end of while
}//end of main

/*Insert First*/
node *insert_first(node *H)
{
    node *ptr=NULL;
    int x;
    // New Node Creation and insert a value to the node
    ptr=(node *)malloc(sizeof(node));
    printf("\nEnter the value:");
    scanf("%d",&x);
    ptr->data=x;
    // New node's next will be updated by Head address
    ptr->next=H;
    //Head will hold the new node's address
    H=ptr;
    printf("\n%d is inserted.",x);
    return H;
}

/*Insert Last*/
node *insert_last(node *H)
{
    node *ptr=NULL;
    node *ptr1=H;
    int x;
    // New Node Creation and insert a value to the node
    ptr=(node *)malloc(sizeof(node));
    printf("\nEnter the value:");
    scanf("%d",&x);
    ptr->data=x;
    if(H==NULL)
    {
        //when Head is NULL,insert first then
        ptr->next=NULL;
        H=ptr;
    }
    else
    {
        while(ptr1->next!=NULL)
        ptr1=ptr1->next;
        ptr1->next=ptr;
        ptr->next=NULL;
    }
    printf("\n%d is inserted.",x);
    return H;
}

/*Delete First*/
node *delete_first(node *H)
{
    node *ptr=H;
    if(H==NULL)
    {
        printf("\n List Underflow.");
    }
    else
    {
        // Replace Head by the 2nd node's address
        H=ptr->next;
        printf("\n%d is deleted.",ptr->data);
        free(ptr);
    }
    return H;
}

/*Delete Last*/
node *delete_last(node *H)
{
    node *ptr=H, *preptr=NULL;
    if(H==NULL)
    {
        printf("\n List Underflow.");
    }
    else if(H->next==NULL)
    {
        //It means there exists only one node
        // then execute delete first operation
        printf("\n %d is deleted.",H->data);
        H=NULL;
        free(ptr);
    }
    else
    {
        //It means there exists more than one node
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        printf("\n %d is deleted.",ptr->data);
        free(ptr);
        preptr->next=NULL;
    }
    return H;
}

/*Insert After A Value*/
node *insert_after_value(node *H)
{
    node *ptr=H, *new_node=NULL;
    int num,val;
    printf("\n Enter the value after which you want to insert:");
    scanf("%d",&num);
    while((ptr->data!=num)&&(ptr->next!=NULL))
    ptr=ptr->next;
    if(ptr==NULL)
    {
        printf("\n %d is not in the list.",num);
    }
    else
    {
        // New Node Creation and insert a value to the node
        new_node=(node *)malloc(sizeof(node));
        printf("\nEnter the value:");
        scanf("%d",&val);
        new_node->data=val;
        new_node->next=ptr->next;
        ptr->next=new_node;
        printf("\n%d is inserted.",val);
    }
    return H;
}

/*Insert Before a Value*/
node *insert_before_value(node *H)
{
    node *ptr=H, *new_node=NULL, *preptr=NULL;
    int num,val;
    printf("\nEnter the value before which you want to insert:");
    scanf("%d",&num);
    while((ptr->data!=num)&&(ptr->next!=NULL))
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("\n%d is not in the list.",num);
    }
    else if(H->data==num)
    {
        //It means Node is to inserted as first node
        // New Node Creation and insert a value to the node
        new_node=(node *)malloc(sizeof(node));
        printf("\nEnter the value:");
        scanf("%d",&val);
        new_node->data=val;
        new_node->next=H;
        H=new_node;
        printf("\n%d is inserted.",val);
    }
    else
    {
        // New Node Creation and insert a value to the node
        new_node=(node *)malloc(sizeof(node));
        printf("\n Enter the value:");
        scanf("%d",&val);
        new_node->data=val;
        preptr->next=new_node;
        new_node->next=ptr;
        printf("\n %d is inserted.",val);
    }
    return H;
}

/*Inserting After Position*/
node *insert_after_position(node *H)
{
    node *ptr=H, *new_node=NULL;
    int count=0, pos=0, val;
    //Node Count
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("\nEnter the position after which you want to insert:");
    scanf("%d",&pos);
    //Validity Checking
    if((pos<0)||(pos>count))
    {
        printf("\nInvalid Position.");
    }
    else
    {
        // New Node Creation and insert a value to the node
        new_node=(node *)malloc(sizeof(node));
        printf("\nEnter the value:");
        scanf("%d",&val);
        new_node->data=val;
        if(pos==0)
        {
            //It means Insert as first node
            new_node->next=H;
            H=new_node;
        }
        else {
            ptr=H;
            pos-=1; // Assignment operator; pos=pos-1
            while(pos!=0)
            {
                pos--;
                ptr=ptr->next;
            }
            new_node->next=ptr->next;
            ptr->next=new_node;
        }
        printf("\n %d is inserted.",val);
    }
    return H;
}

/*Insert Before a Position*/
node *insert_before_position(node *H)
{
    node *ptr=H, *new_node=NULL;
    int count=0, pos=0, val;
    //Node Count
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("\nEnter the position before which you want to insert:");
    scanf("%d",&pos);
    //Validity Cheching
    if((pos<=0)||(pos>count))
    {
        printf("\nInvalid Position.");
    }
    else
    {
        new_node=(node *)malloc(sizeof(node));
        printf("\nEnter the value:");
        scanf("%d",&val);
        new_node->data=val;
        if(pos==1)
        {
            new_node->next=H;
            H=new_node;
        }
        else
        {
            ptr=H;
            while(pos>2)
            {
                ptr=ptr->next;
                pos--;
            }
            new_node->next=ptr->next;
            ptr->next=new_node;
        }
        printf("\n%d is inserted.",val);
    }
    return H;
}

/*Delete After A Value*/
node *delete_after_value(node *H)
{
    node *ptr=H, *ptr1=NULL;
    int num,val;
    printf("\nEnter the Value after which you want to delete:");
    scanf("%d",&num);
    if(H==NULL)
        printf("\n List is Empty.");
    else
    {
        while((ptr->data!=num)&&(ptr->next!=NULL))
        {
            ptr1=ptr;
            ptr=ptr->next;
        }

        if(ptr==NULL)
        {
            printf("\n %d is not the list.",num);
        }
        else
        {
            if(H->data==num)
            {
                //Delete first operation need to be executed
                ptr1=H->next;
                H->next=ptr1->next;
                printf("\n %d is deleted.",ptr1->data);
                free(ptr1);
            }
            else
            {
                ptr1=ptr->next;
                ptr->next=ptr1->next;
                printf("\n %d is deleted.",ptr1->data);
                free(ptr1);
            }
        }
    }
    return H;
}

/*Delete Before Value*/
node *delete_before_value(node *H)
{
    node *ptr=H, *ptr1=NULL, *ptr2=NULL;
    int num,val;
    printf("\nEnter the Value before which you want to delete:");
    scanf("%d",&num);
    if(H==NULL)
    printf("\nList Empty.");
    else
    {
        while((ptr->data!=num)&&(ptr->next!=NULL))
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("\n %d is not the list.",num);
        }
        else if(ptr==H)
        {
            printf("\n Sorry, no values can be deleted.");
        }
        else
        {
            if(H->next->data==num)
            {
                //Delete first operation
                H=ptr;
                printf("\n%d is deleted.",ptr1->data);
                free(ptr1);
            }
            else
            {
                ptr=H;
                while(ptr->data!=ptr1->data)
                {
                    ptr2=ptr;
                    ptr=ptr->next;
                }
                ptr2->next=ptr->next;
                printf("\n%d is deleted.",ptr1->data);
                free(ptr);
            }
        }
    }
    return H;
}

/*Delete a Position*/
node *delete_position(node *H)
{
    node *ptr=H, *ptr1=NULL;
    int pos,count=0;
    //Node Count
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    if(count==0)
        printf("\nList is empty.");
    else
    {
        printf("\nEnter the position which you want to delete: ");
        scanf("%d",&pos);
        ptr=H;
        if((pos<=0)||(pos>count))
            printf("\nDeleting this position not possible.");
        else
        {
            if(pos==1)
            {
                //It means Delete First Node
                H=ptr->next;
                printf("\n%d is deleted.",ptr->data);
                free(ptr);
            }
            else
            {
                while(pos!=1)
                {
                    pos--;
                    ptr1=ptr;
                    ptr=ptr->next;
                }
                ptr1->next=ptr->next;
                printf("\n%d is deleted.",ptr->data);
                free(ptr);
            }
        }
    }
    return H;
}

/*Display*/
node *display(node *H)
{
    node *ptr=H;
    if(ptr==NULL)
        printf("\nList Underflow.");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
    return H;
}

/*Reverse Display*/
void reverse_display(node *H)
{
    if(H==NULL)
        return;
    reverse_display(H->next);
    printf("%d\t",H->data);
}

/*Physically Reverse Display*/
node *physically_reverse_display(node *H)
{
    node *p, *q, *temp;
    p=H;
    q=NULL;
    while(p!=NULL)
    {
        temp=p;
        p=p->next;
        temp->next=q;
        q=temp;
    }
    return q;
}

/*Free All Nodes*/
node *free_all_nodes(node *H)
{
    node *ptr=H, *ptr1=NULL;
    if(ptr==NULL)
        printf("\nList is already empty.");
    else
    {
        while(ptr!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
            free(ptr1);
        }
    }
    H=NULL;
    return H;
}

/*Node Count*/
node *node_count(node *H)
{
    node *ptr=H;
    int count=0;
    //Node Counting loop
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("\nNumber of nodes in the list is: %d",count);
    return H;
}

/*Delete first nth nodes*/
node *del_first_n_nodes(node *H)
{
    node *ptr=H, *ptr1=NULL;
    int n,count=0,temp;
    //Node Count
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    if(count==0)
    {
        printf("\n List is empty.");
        printf("\n Deletion Not Possible");
    }
    else
    {
        printf("\n Enter the number of nodes you want to delete from beginning:");
        scanf("%d",&n);
        temp=n;
        if((n<=0)||(n>count))
        {
            printf("\n Invalid input.");
        }
        else
        {
            ptr=H;
            while(n!=0)
            {
                ptr1=ptr->next;
                free(ptr);
                n--;
                ptr=ptr1;
            }
            H=ptr1;
            printf("\n First %d nodes are deleted.",temp);
        }
    }
    return H;
}

/*Delete Last n nodes*/
node *del_last_n_nodes(node *H)
{
    node *ptr=H, *ptr1=NULL;
    int n,count=0,temp;
    //Node Count
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    if(count==0)
        printf("\n List is empty.");
    else
    {
        printf("\nEnter the number of nodes you want to delete from last:");
        scanf("%d",&n);
        temp=n;
        if((n<=0)||(n>count))
        {
            printf("\nInvalid input.");
        }
        else if(n==count)
        {
            //All nodes have to be deleted.
            ptr=H;
            while(ptr!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->next;
                free(ptr1);
            }
            H=NULL;
            printf("\n Last %d nodes are deleted.",temp);
        }
        else
        {
            ptr=H;
            n=count-n;
            while(n!=0)
            {
                ptr1=ptr;
                ptr=ptr->next;
                n--;
            }
            while(ptr!=NULL)
            {
                ptr1->next=ptr->next;
                free(ptr);
                ptr=ptr1->next;
            }
            printf("\n Last %d nodes are deleted.",temp);
        }
    }
    return H;
}