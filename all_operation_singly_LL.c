#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void in_beg();
void in_end();
void in_loc();
void count();
void delete_beg();
void delete_end();
void delete_pos();
void reverse();
void sum();
void middle();
void cycle_detection();
void node_value();

void main()
{
    int ch;
    while (1)
    {
        printf("\n1. Create\n2. Display\n3. Insert at beginning\n4. Insert At End\n5. Insert at given location\n6. Count\n7. Delete beg\n8. Delete end\n9. Delete at given position\n10. Reverse\n11. Sum\n12. Middle of Node\n13. Cycle Detection\n14. Node value\n15. Exit\n");

        printf("---------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            in_beg();
            break;
        case 4:
            in_end();
            break;
        case 5:
            in_loc();
            break;
        case 6:
            count();
            break;
        case 7:
            delete_beg();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            delete_pos();
            break;
        case 10:
            reverse();
            break;
        case 11:
            sum();
            break;
        case 12:
            middle();
            break;
        case 13:
            cycle_detection();
            break;
        case 14:
            node_value();
            break;
        case 15:
            exit(0);
            break;
        default:
            printf("Invalid");
            break;
        }
    }
}

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp = NULL;

void create()
{
    struct node *new_node;
    int item;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter any data : ");
    scanf("%d", &item);
    new_node->data = item;
    new_node->next = NULL;  //new_node->next = head; for cycle detection

    if (head == NULL)
    {
        head = new_node;
        temp = head;
    }
    else
    {
        temp->next = new_node;
        temp = new_node;
    }
    printf("\nNode inserted successfully\n");
}

void display()
{
    struct node *current;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        current = head;
        while (current != NULL)  //while (current->next != head) for cycle detection
        {
            printf("%d----->", current->data);
            current = current->next;
        }
        // printf("%d", current->data); for cycle detection
        printf("NULL\n");
    }
}

void count()
{

    int count = 0;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("%d", count);
    }
}

void in_beg()
{
    struct node *new_node, *temp = head;
    int item;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data at beginning : ");
    scanf("%d", &item);
    new_node->data = item;
    if (head == NULL)
    {
        head = new_node;
        temp = head;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    printf("\nNode inserted at begenning successfully\n");
}

void in_end()
{
    struct node *new_node, *temp = head;
    int item;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at end : ");
    scanf("%d", &item);
    new_node->data = item;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        temp = head;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("\nNode inserted at end successfully\n");
}

void in_loc()
{
    struct node *new_node, *temp = head;
    int item, pos, i=1;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    
    int count = 0;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
    }
    if (pos > count)
    {
        printf("\nInvalid Position");
    }
    else
    {
        temp = head;
        while (i < pos)  //while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        printf("\nEnter data : ");
        scanf("%d", &item);
        new_node->data = item;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void delete_beg()
{
    struct node *temp = head;
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end()
{
    struct node* pre_node, *temp = head;
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp = head;
        pre_node = head;
        while (temp->next != NULL)
        {
            pre_node = temp;
            temp = temp->next;
        }
        if(temp == head)
        {
            head = NULL;
            temp = head;
        }
        else
        {
            pre_node->next = NULL;
        }
        free(temp);
    }
}
void delete_pos()
{
    struct node *new_node;
    int pos, i = 1;
    temp = head;
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    while(i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    new_node = temp->next;
    temp->next = new_node->next;
    free(new_node);  
}

void reverse()
{
    struct node *prev_node, *curr_node, *next_node;
    prev_node = NULL;
    curr_node = next_node = head;
    while (next_node != NULL)
    {
        next_node = next_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node; 
}


void sum()
{
    int sum = 0;
    struct node *node = head;
    if(head == NULL)
    {
        sum = sum + head->data;
    }
    else
    {
        while (node != NULL)
        {
            sum = sum + node->data;
            node = node->next;
        }  
    }
    printf("\n%d", sum);
}

void middle()
{
    struct node *slow, *fast;
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }
    else
    {
        slow = head;
        fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("The middle node is: %d\n", slow->data);
    }
}

void cycle_detection()
{
    struct node *slow, *fast;
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }
    else
    {
        slow = head;
        fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
        {
            printf("There is cycle in linked list");
            return;
        }
        }
        printf("There is no cycle in linked list");    
    }
}

void node_value()
{
    struct node *get;
    int count = 0, pos;
    
    get = head;
    while (get != NULL)
    {
        count++;
        get = get->next;
    }
    
    // get = head;
    count = count - 1;

    printf("\nPosition from tail = ");
    scanf("%d", &pos);

    while (get->next != NULL)
    {
        if(count == pos - 1)
        {
            break;
        }
        get = get->next;
        count--;
    }
    printf("\n%d is the node value", get->data) ;
}