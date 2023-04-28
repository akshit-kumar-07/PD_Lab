#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node 
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};
struct node* create_node(int k)
{
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->key=k;
    tmp->p=NULL; tmp->right=NULL; tmp->left=NULL;
    return tmp;
}
struct node* insert(struct node *root,int k)
{
    struct node *x,*y,*z;
    x=root; y=NULL; z=create_node(k);
    while(x!=NULL)
    {
        y=x;
        if(z->key<x->key) x=x->left;
        else x=x->right;
    }
    z->p=y;
    if(y==NULL)
        root=z;
    else if(z->key<y->key) y->left=z;
    else y->right=z;
    return root;
}
void preorder(struct node *x)
{
    //printf("( ");
    if(x==NULL)
    {
        //printf("( ) ");
        printf("( ) ");
        return;
    }
    printf("( ");
    printf("%d ",x->key);
    //printf(" )");
    //printf("( ");
    preorder(x->left);
   // printf(" )");
    //printf("( ");

    preorder(x->right);
    printf(") ");
    return;
    
}
int main()
{
    char ch;int k;
    struct node *x=NULL;
    while(1)
    {
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'i':
                scanf("%d",&k);
                x=insert(x,k);
                break;
            case 'p':
                preorder(x);
                printf("\n");
                break;
            case 'e':exit(0);
            default: break;
        }
    }
    return 0;
}
