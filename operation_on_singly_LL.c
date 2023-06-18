#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node sll;
sll *head = NULL, *temp = NULL;

void create()
{
    sll *new_node = (sll *)malloc(sizeof(sll));

    int item;
    printf("\nEnter any data : ");
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
        temp->next = new_node;
        temp = new_node;
    }
    printf("\nSuccess");
}

void display()
{
    sll *current;
    if (head == NULL)
    {
        printf("\nEmpty");
        return;
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            printf("%d---->", current->data);
            current = current->next;
        }
        printf("Null\n");
    }
}

void in_beg()
{
    sll *new_node = (sll *)malloc(sizeof(sll));

    int item;
    printf("\nEnter any data : ");
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
    printf("\nSuccess");
}

void in_end()
{
    sll *new_node = (sll *)malloc(sizeof(sll));

    int item;
    printf("\nEnter any data : ");
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
        temp = new_node;
    }
    printf("\nSuccess");
}

void in_loc()
{
    sll *new_node = (sll *)malloc(sizeof(sll));

    int item;
    int pos, i = 1;
    int count = 0;
    sll *temp = head;
    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("\nEmpty");
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
        printf("\nInvalid");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
        }
        int item;
        printf("\nEnter any data : ");
        scanf("%d", &item);

        new_node->data = item;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void d_beg()
{
    sll *tmep = head;

    if (head == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void d_end()
{
    sll *pre_node, *temp = head;
    if (head == NULL)
    {
        printf("\nUnderflow");
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

        if (temp == head)
        {
            temp = head;
            head = NULL;
        }
        else
        {
            pre_node->next = NULL;
        }
        free(temp);
    }
}

void d_loc()
{
    sll *del_node, *temp = head;
    int i = 1, pos;
    printf("\nEnter the position : ");
    scanf("%d", &pos);

    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    del_node = temp->next;
    temp->next = del_node->next;
    free(del_node);
}

void reverse()
{
    sll *curr, *prev, *next_n;
    next_n = head;
    curr = head;
    prev = NULL;

    while (next_n != NULL)
    {
        next_n = next_n->next;
        curr->next = prev;
        prev = curr;
        curr = next_n;
    }
    head = prev;
}

void sum()
{
    sll *node = head;
    int sum = 0;

    if (head == NULL)
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
    printf("\nSum : %d", sum);
}

void middle()
{
    sll *slow, *fast;
    slow = head;
    fast = head;

    if (head == NULL)
    {
        printf("\nEmpty");
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
        printf("\nMiddle node data = %d", slow->data);
    }
}

void cycle_det()
{
    sll *slow, *fast;
    slow = head;
    fast = head;

    if (head == NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        slow = head;
        fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                printf("\nCycle is present");
            }
        }
        printf("\nNo cycle is present");
    }
}

void get_node()
{
    sll *get;
    int count = 0, pos;

    get = head;

    while (get != NULL)
    {
        count++;
        get = get->next;
    }

    count = count - 1;

    printf("\nPosition from tail = ");
    scanf("%d", &pos);

    get = head;
    while (get != NULL)
    {
        if (count == pos - 1)
        {
            break;
        }
        get = get->next;
        count--;
    }
    printf("\n%d is your desired list", get->data);
}

int main()
{
    int listSize;
    printf("Enter the size of the list: ");
    scanf("%d", &listSize);

    for (int i = 0; i < listSize; i++)
    {
        create();
    }

    printf("\nLinked List: ");
    display();

    printf("\nInsert beginning : ");
    in_beg();

    printf("\nLinked List: ");
    display();

    printf("\nInsert end : ");
    in_end();

    printf("\nLinked List: ");
    display();

    printf("\nDelete beg List: ");
    d_beg();

    printf("\nLinked List: ");
    display();

    printf("\nDelete loc List: ");
    d_loc();

    printf("\nLinked List: ");
    display();

    printf("\nDelete End List: ");
    d_end();

    printf("\nLinked List: ");
    display();

    printf("\nReversed List: ");
    reverse();

    printf("\nLinked List: ");
    display();

    printf("\nSum List: ");
    sum();

    printf("\nLinked List: ");
    display();

    printf("\nMiddle of List: ");
    middle();

    printf("\nLinked List: ");
    display();

    printf("\nGet node from tail List: ");
    get_node();

    return 0;
}