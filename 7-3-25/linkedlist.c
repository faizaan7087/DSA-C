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
    } //append node

    void insertatbegin(int x)
    {

        snode*tempnode=head;
        snode*newnode=NULL;
        newnode=(snode *)malloc(sizeof (snode));
        newnode -> data = x;
        newnode -> next = tempnode;
        head = newnode;
    }  //insert at begin\

    void deleteLnode()
    {

        snode*tempnode=head;
        snode*collect=NULL;
        while(tempnode->next-> next != NULL )
           {
            tempnode = tempnode-> next;
           }
           tempnode->next = collect;
           tempnode->next = NULL;
           free(collect);



    }


    void main()
    {
        createlist(10);
        appendnode(20);
        appendnode(30);
        insertatbegin(5);
        deleteLnode();
        printlist();

    }



