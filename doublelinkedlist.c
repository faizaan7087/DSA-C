#include <stdio.h>
#include <stdlib.h>
struct node
{

    int data;
    struct node *next;
    struct node *prev;

};
typedef struct node dnode;
dnode *head = NULL;
void createlist(int x)
{

    dnode *newnode = NULL;
    newnode = (dnode*)malloc(sizeof(dnode));
    newnode -> data = x;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    head = newnode;

}
void appendnode(int x)
{

    dnode *tempnode = head;
    dnode *newnode = NULL;
    newnode=(dnode*)malloc(sizeof(dnode));
    newnode -> data = x;
    newnode -> next = NULL;
    if(tempnode == NULL)
    {

        head = newnode;
        return;
    }
    while(tempnode->next != NULL)
    {

        tempnode = tempnode->next;

    }
    tempnode ->next = newnode;
    newnode -> prev = tempnode;
}
void printlist(void)
{

    dnode *tempnode = head;
    if(tempnode == NULL)
    {

        printf("the list is empty\n");
    }
    while(tempnode != NULL)
    {

        printf("%d\n", tempnode ->data);
        tempnode = tempnode -> next;
    }
    return;
}
void insertab(int x)
{

    dnode *tempnode = head;
    dnode *newnode = NULL;
    newnode =(dnode*)malloc(sizeof(dnode));
    newnode -> data = x;
    tempnode -> prev = newnode;
    newnode -> next = tempnode;
    newnode -> prev = NULL;
    head = newnode;
}
void delfnode(void) // delete first node
{

    dnode *tempnode = head;
    head = tempnode-> next;
    free(tempnode);
    printf("the first element is deleted\n");
}
void dellnode(void) //delete last node
{

    dnode *tempnode = head;
    dnode *collect = NULL;
    while(tempnode -> next->next != NULL)
    {

        tempnode = tempnode->next;

    }
    tempnode -> next = collect;
    free(collect);
    printf("the last node deleted\n");

}
void search(int x)
{

    dnode *tempnode = head;
    while ( tempnode != NULL)
    {
        
        
        if(tempnode->data == x)
        {
            printf("the element found\n");
            return;
        }
        tempnode = tempnode->next;
    }
    printf("the element not found\n");
    return;

}
int main()
{

    createlist(10);
    appendnode(20);
    insertab(30);
    printlist();
    delfnode();
    dellnode();
    printlist();
    search(10);
    return 0;
}
