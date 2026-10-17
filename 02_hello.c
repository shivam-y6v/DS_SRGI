
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *ptr, *head = NULL, *temp, *atemp;
    int n, i, x, val, loc;

    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter node data: ");
        scanf("%d", &x);

        temp = malloc(sizeof(struct node));
        temp->data = x;
        temp->link = NULL;

        if (head == NULL)
        {
            head = temp;
            ptr = temp;
        }
        else
        {
            ptr->link = temp;
            ptr = temp;
        }
    }

    printf("Enter new value and location: ");
    scanf("%d %d", &val, &loc);

    if (loc < 1 || loc > n + 1)
    {
        printf("Invalid location");
        return 0;
    }

    atemp = malloc(sizeof(struct node));
    atemp->data = val;

    if (loc == 1)
    {
        atemp->link = head;
        head = atemp;
    }
    else
    {
        ptr = head;

        for (i = 1; i < loc - 1; i++)
        {
            ptr = ptr->link;
        }

        atemp->link = ptr->link;
        ptr->link = atemp;
    }

    printf("Linked list after insertion:\n");

    ptr = head;

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }

    printf("NULL\n");

    return 0;
}