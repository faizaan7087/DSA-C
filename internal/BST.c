#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node tnode;
tnode* createnode(int val)
{
    tnode* newnode = NULL;
    newnode=(tnode*)malloc(sizeof(tnode));
    newnode->data= val;
    newnode-> left = NULL;
    newnode -> right = NULL;
    return newnode;
}
tnode* buildtree(tnode* root , int val)
{
    if(root==NULL)
    {
        return (createnode(val));
    }
    if(val < root->data)
    {
        root->left = buildtree(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = buildtree(root->right, val);
    }
    return root;
}
void inorder(tnode*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int findmin(tnode*root)
{
    if(root == NULL)
    {
        printf("The tree is empty.....");
        
    }
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root->data;
}
int findmax(tnode*root)
{
    if(root == NULL)
    {
        printf("The tree is empty.....");
        
    }
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root->data;
}
int main(){
    tnode*root=NULL;
    int arr[]= {50,10,60,20,70,30,80};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n ; i++)
    {
        root= buildtree(root, arr[i]);
    }
    printf("Inorder:");
    inorder(root);
    printf("\n The min element is : %d \n",findmin(root));
    printf("\n The max element is : %d ",findmax(root));
}