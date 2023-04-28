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
void inorder(struct node *x)
{
    if(x==NULL)return;
    inorder(x->left);
    printf("%d ",x->key);
    inorder(x->right);
    return;
}
void preorder(struct node *x)
{
    if(x==NULL) return;
    printf("%d ",x->key);
    preorder(x->left);
    preorder(x->right);
    return;
}
void postorder(struct node *x)
{
    if(x==NULL) return;
    postorder(x->left);
    postorder(x->right);
    printf("%d ",x->key);
    return;
}
struct node* insert(struct node *x,int k)
{
    
    if(x==NULL)
        {x=create_node(k);return x;}
    if(k<x->key)
        x->left= insert(x->left,k);
    else
        x->right=(insert(x->right,k));
    return x;
}
struct node* search(struct node *x,int k)
{
    if(x==NULL || x->key==k) return x;
    if(k<x->key) return search(x->left,k);
    else  return search(x->right,k);
}
void find_min(struct node *x)
{
    if(x==NULL)
    {printf("NIL\n");return;}
    while(x->left!=NULL) x=x->left;
    printf("%d\n",x->key);
    return;
}
void find_max(struct node *x)
{
    if(x==NULL)
    {printf("NIL\n");return;}
    while(x->right!=NULL) x=x->right;
    printf("%d\n",x->key);
    return;
}
int main()
{
    char ch;
    int k1,k2;
    struct node *x=NULL;struct node *chk;
    while(1)
    {
        scanf(" %c",&ch);getchar();
        switch(ch)
        {
            case 'a':
                scanf("%d",&k1);
                x=insert(x,k1);
                break;
            case 's':
                scanf("%d",&k2);
                chk=search(x,k2);
                (chk==NULL)?(printf("NotFound\n")):printf("Found\n");
                break;
            case 'x':
                find_max(x);
                break;
            case 'n':
                find_min(x);
                break;
            case 'i':
                inorder(x);
                printf("\n");
                break;
            case 'p':
                preorder(x);
                printf("\n");
                break;
            case 't':
                postorder(x);
                printf("\n");
                break;
            case 'e':
                return 0;
            default: break;
        }
    }
    return 0;
}
