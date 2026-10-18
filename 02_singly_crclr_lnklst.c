#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
int main()
{
    int n,x,i,val,loc;
    printf("enter node:");
    scanf("%d",&n);
    struct node *temp,*head,*ptr,*atemp;

    for(i=1;i<=n;i++)
    {
        printf("enter value:");
        scanf("%d",&x);
        temp=(struct node*)malloc(sizeof(struct node));

        temp->data=x;

        if(i==1)
        {
            head=temp;
            ptr=head;
        }
        else{
            ptr->link=temp;
            ptr=temp;
        }

    }
    ptr->link=head;
    printf("enter new value and location:");
    scanf("%d %d",&val ,&loc);
    atemp=(struct node*)malloc(sizeof(struct node));

    atemp->data=val;

    int count=1;
    ptr=head;
    while(1)

    {
        if(loc==1)
        {
            atemp->link=head;
            temp->link=atemp;
            head=atemp;
            break;
        }
        else if((loc==count)&&(ptr!=head))
        {
            temp->link=atemp;
            atemp->link=ptr;
            break;
        }
        else if((loc==count)&&(ptr==head)){
            temp->link=atemp;
            atemp->link=head;
            break;
        }
        count++;
        temp=ptr;
        ptr=ptr->link;
    }
    ptr=head;
    do{
        printf("\n%d",ptr->data);
        ptr=ptr->link;
    }
    while(ptr!=head);
    return 0;
}