// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int data;
//     struct node*link;   
// };
// int main()
// {
//     struct node *ptr,*head,*temp,*atemp;
//     int n,i,x,val,loc;
//     printf("enter no. of node ");
//     scanf("%d",&n);

//     for(i=1;i<=n;i++)
//     {
//         printf("enter node");
//         scanf("%d",&x);
//         temp=(struct node*)malloc(sizeof(struct node));

//         temp->data=x;
//         if(i==1)
//         {
//             temp=head;
//             ptr=temp;
//         }
//         else{
//             ptr->link=temp;
//             ptr=temp;


//         }


//     }
//     ptr->link=NULL;
//     printf("enter new value and location");
//     scanf("%d %d",&val,&loc);
//     atemp=(struct node*)malloc(sizeof(struct node));
//     atemp->data=val;
//     int count=1;
//     ptr=head;
//     while(1)
//     {
//         if(loc==1){
//         atemp->link=head;
        
//         head=atemp;
//         break;
//         }

//         else if((loc==count) && (ptr!=NULL))
//         {
//             temp->link=atemp;
//             atemp->link=ptr;
//             break;
//         }
//         else if((loc==count) && (ptr==NULL))
//         {
//             temp->link=atemp;
//             atemp->link=NULL;
//             break;
//         }
//         count++;
//         temp=ptr;
//         ptr=ptr->link;


        
//     }
//     ptr=head;
//     do
//     {
//         printf("\n %d",&ptr->data);
//         ptr=ptr->link;
//     }
//     while(ptr!=NULL);
//     return 0;
// }


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
