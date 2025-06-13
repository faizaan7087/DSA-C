#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
typedef struct node snode;
snode*head=NULL;
void enque(int n)
{
    snode*temp= NULL;
    snode*tempn=head;
    temp= (snode*)malloc(sizeof(snode));
    temp->data=n;
    temp->next=NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    while(tempn->next != NULL)
    {
        tempn=tempn->next;
    }
    tempn->next=temp;
}
void deque()
{
    snode*temp=head;
    snode*collect=NULL;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    collect = temp->next;
    temp->next = NULL;
    free(collect);
}
void print()
{
    snode*temp=head;
    printf("the elements are:\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    enque(20);
    enque(30);
    enque(40);
    deque();
    print();

}