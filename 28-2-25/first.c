#include <stdio.h>
#include <stdlib.h>


    struct node
    {
        int data;
        struct node*next;

    };
    typedef struct node snode;
    snode*head = NULL;

    void createlist(int x)
    {
        snode*newnode= NULL;
        newnode=(snode*)malloc(sizeof(snode));
        newnode -> data = x;
        newnode -> next = NULL;
        head = newnode;
    } // createlist

    void printlist(void)
    {

        snode*tempnode=head;
        if(tempnode == NULL)
        {
            printf("the list is empty\n");
            return;

        }
        while(tempnode!=NULL)
        {

            printf("%d \n",tempnode -> data);
            tempnode = tempnode -> next;
        }
    } //printlist

    void appendnode(int x)
    {
        snode*tempnode = head;

        snode*newnode = NULL;
        newnode=(snode*)malloc(sizeof(snode));
        newnode -> data = x;
        newnode -> next = NULL;

        if(tempnode == NULL)
        {
            head = newnode;
            return;
        }

        while(tempnode-> next != NULL )
           {
            tempnode = tempnode-> next;
           }

        tempnode-> next = newnode;
        return ;
    } //appendnode

    void main()
    {
        createlist(10);
        printlist();
        appendnode(20);
        appendnode(30);
        printlist();

    }



