
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * insertIter(struct Node * root)
{
    struct Node * ptr,*parentptr,*nodeptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    int val;
    printf("\nEnter Value ");
    scanf("%d",&val);
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    if(root==NULL)
    {
        root=ptr;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        parentptr=NULL;
        nodeptr=root;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data)
                nodeptr=nodeptr->left;
            else
                nodeptr=nodeptr->right;
        }
    }
    return root;
};
void inOrder(struct Node * root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("\n%d ",root->data);
        inOrder(root->right);
    }
}
void main()
{
    struct Node * tree=NULL;
    int option;
    while(1)
    {
        printf("\n1 for insert ");
        printf("\n2 for in order ");
        printf("\n0 for exit ");
        scanf("%d",&option);
        if(option==1)
        {
            tree=insertIter(tree);
        }
        else if(option==2)
        {
            inOrder(tree);
        }
        else if(option==0)
        {
            break;
        }
    }
}
