#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node * right;
};
struct Node * createNode(int data)
{
    struct Node * n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
};
void preOrder(struct Node * root)
{
    if(root!=NULL)
    {
        printf("\n%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
};
void postOrder(struct Node * root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("\n%d ",root->data);
    }
}
void inorder(struct Node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("\n%d ",root->data);
        inorder(root->right);
    }
}
void main()
{
    struct Node *p=createNode(7);
    struct Node *p1=createNode(2);
    struct Node *p2=createNode(1);
    struct Node *p3=createNode(0);
    struct Node *p4=createNode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("\nPre Order Traversal ");
    preOrder(p);
    printf("\nPost Order Traversal ");
    postOrder(p);
    printf("\nIn Order Traversal ");
    inorder(p);
}
