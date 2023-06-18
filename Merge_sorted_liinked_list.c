#include <stdio.h>
#include <stdlib.h>
void create();

struct node
{
    int data;
    struct node *next;
};
typedef struct node merge;
merge *head = NULL, *temp = NULL;
merge *head1 = NULL, *head2 = NULL;

void create(merge **head)
{
    merge *new_node;
    int item;
    new_node = (merge *)malloc(sizeof(merge));
    printf("\nEnter any data : ");
    scanf("%d", &item);
    new_node->data = item;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        temp = *head;
    }
    else
    {
        temp->next = new_node;
        temp = new_node;
    }
    printf("\nNode inserted successfully\n");
}

void display(merge *head)
{
    merge *current;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            printf("%d----->", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

merge *merge_ll(merge *list_1, merge *list_2)
{
    if (list_1 == NULL)
    {
        return list_2;
    }
    if (list_2 == NULL)
    {
        return list_1;
    }

    merge *result = NULL;

    if (list_1->data <= list_2->data)
    {
        result = list_1;
        result->next = merge_ll(list_1->next, list_2);
    }
    else
    {
        result = list_2;
        result->next = merge_ll(list_2->next, list_1);
    }

    return result;
}

int main()
{
    int n, m;

    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n);

    printf("\nCreating the first linked list:\n");

    for (int i = 0; i < n; i++)
    {
        create(&head1);
    }

    printf("Enter the number of elements for the second list: ");
    scanf("%d", &m);

    printf("\nCreating the second linked list:\n");

    for (int i = 0; i < m; i++)
    {
        create(&head2);
    }

    printf("\nFirst Linked List:");
    display(head1);

    printf("\nSecond Linked List:");
    display(head2);

    merge *merged_list = merge_ll(head1, head2);

    printf("\nSecond Linked List:");
    display(merged_list);
}
