#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    int height;
    struct node* left;
    struct node* right;
};
typedef struct node tnode;
tnode* createnode(int data)
{
    tnode* new = NULL;
    new = (tnode*)malloc(sizeof(tnode));
    new->data = data;
    new->height = 1;
    new->left = new->right = NULL;
    return new;
}
int getHeight(tnode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->height;
}
void updateHeight(tnode* root)
{
    root->height=1+(getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));
    return;
}
int getBalance(tnode* root)
{
    return (getHeight(root->left)-getHeight(root->right));
}
tnode* rightrotation(tnode* root){
    tnode* temp = root->left;
    root->left = temp->right;
    temp->right = root;

    updateHeight(root);
    updateHeight(temp);
    return temp;
}
tnode* leftrotation(tnode* root){
    tnode* temp = root->right;
    root->right = temp->left;
    temp->left = root;

    updateHeight(root);
    updateHeight(temp);
    return temp;
}

tnode* reBalance(tnode* root){
    int balancefactor = getBalance(root);
    if( balancefactor > 1 && getBalance(root->left) >= 0)
    {
         return rightrotation(root);
    }
    if(balancefactor > 1 && getBalance(root->left) > 0)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if(balancefactor < -1 && getBalance(root->right) <= 0)
    {
        return leftrotation(root);
    }
    if(balancefactor < -1 && getBalance(root->right) < 0)
    {
        root->right=rightrotation(root->right);
        return leftrotation(root);
    }
    return root;

}
tnode* insert(tnode* root, int val)
{
    if(root == NULL){
        return createnode(val);
    }
    if(val < root-> data){
        root->left = insert(root->left, val);
    }
    else if(val > root-> data){
        root->right = insert(root->right, val);
    }
    else {
        printf("%d element is already exist",val);
        return root;
    }
    updateHeight(root);
    return reBalance(root);
}
void inorder(tnode* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
tnode* findmin(tnode* root){
    if(root == NULL)
    {
        printf("the tree is empty");
        return NULL;
    }
    while(root->left != NULL){
        root= root->left;
    }
    return root;
}
tnode* delete(tnode* root,int val)
{
    if(root == NULL){
        return NULL;
    }
    if(val < root-> data)
    {
        root->left = delete(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = delete(root->right, val);
    }
    else{
        if(root->left == NULL || root->right == NULL)
        {
            tnode* temp = root->left ? root->left : root->right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }
            free(temp);
        }
        else{
            tnode* temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    if(root == NULL)
    {
        return NULL;
    }
    updateHeight(root);
    return reBalance(root);

}
int main()
{
    tnode* root = NULL;

    int vals[] = {10, 20, 30, 15, 25, 5, 35, 4, 3};
    int n = sizeof(vals)/sizeof(int);

    for(int i =0; i < n; i++){
       root = insert(root, vals[i]);
    }
    delete(root,10);
    inorder(root);
    printf("\n");
    return 0;
}