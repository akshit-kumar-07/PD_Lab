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
struct node* find_min(struct node *x)
{
    if(x==NULL)
    {printf("NIL\n");return NULL;}
    while(x->left!=NULL) x=x->left;
    //printf("%d\n",x->key);
    return x;
}
struct node* find_max(struct node *x)
{
    if(x==NULL)
    {printf("NIL\n");return NULL;}
    while(x->right!=NULL) x=x->right;
    //printf("%d\n",x->key);
    return x;
    //return;
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
struct node* successor(struct node *x)
{
    if(x->right!=NULL) return find_min(x->right);
    struct node *y=NULL;
    y=x->p;
    while(y!=NULL && x==y->right)
    {
        x=y;
        y=y->p;
    }
    return y;
}
struct node* predecessor(struct node *x)
{
    if(x->left!=NULL) return find_max(x->left);
    struct node *y=NULL;
    y=x->p;
    while(y!=NULL && x==y->left)
    {
        x=y;
        y=y->p;
    }
    return y;
}
struct node* search(struct node *x,int k)
{
    if(x==NULL || x->key==k) return x;
    if(k<x->key) return search(x->left,k);
    else  return search(x->right,k);
}
/*struct node* transplant(struct node **root,struct node **u,struct node **v)
{
    if((*u)->p==NULL)
    {
        *root=*v;
        return *root;
    }
    else if(*u==(*u)->p->left)
        (*u)->p->left=*v;
    else (*u)->p->right=*v;
    if(*v!=NULL)
        (*v)->p=(*u)->p;
    return *u;
}
void del(struct node **root,int k)
{
    struct node *y,*z;
    z=create_node(k);
    y=NULL;
    if(z->left==NULL)
        transplant(&(*root),&z,&(z->right));
    else if (z->right==NULL)
        transplant(&(*root),&z,(&z->left));
    else{
        y=find_min(z->right);
        if(y->p!=z)
        {   
            transplant(&(*root),&y,(&y->right));
            y->right=z->right;
            y->right->p=y;
        }
        transplant(&(*root),&z,&y);
        y->left=z->left;
        y->left->p=y;
        //return root;
    }
}
struct node* del(struct node *root,int key)
{
    if(!root) return NULL;
    struct node *oldl,*oldr,*succ;
    if(key<root->key)
    {
        root->left=del(root->left,key);
        return root;
    }
    if(key>root->key)
    {
        root->right=del(root->right,key);
        return root;
    }
    oldl=root->left;oldr=root->right;
    if(!oldl) return oldr;
    if(!oldr) return oldl;
    if(oldr->left==NULL)
    {
        oldr->left=oldl;
        return oldr;
    }
    if(oldl->left==NULL)
    {
        oldl->right=oldr;
        return oldl;
    }
    succ=successor(root);
    root=succ->left;
    succ->left=root->right;
    root->left=oldl;
    root->right=oldr;
    return root;
}*/
struct node* del(struct node *root,int k)
{
    if(root==NULL) return root;
    if(root->key>k) 
    {
        root->left=del(root->left,k);
        return root;
    }
    if(root->key<k)
    {
        root->right=del(root->right,k);
        return root;
    }
    else 
    {
        if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
    }
    struct node *suc=successor(root);
    root->key=suc->key;
    root->right=del(root->right,suc->key);
    return root;
}
int main()
{
    char ch;
    int k1,k2,k3;
    struct node *x=NULL;struct node *chk,*s,*p,*d;
    while(1)
    {
        scanf(" %c",&ch);getchar();
        switch(ch)
        {
            case 'a':
                scanf("%d",&k1);
                x=insert(x,k1);
                break;
            case 'i':
                inorder(x);
                printf("\n");
                break;
            case 'c':
                scanf("%d",&k2);
                s=search(x,k2);
                if(s==NULL || (successor(s))==NULL) 
                {
                    printf("NotFound\n");
                    break;
                }
                printf("%d\n",((successor(s)))->key);
                break;
            case 'r':
                scanf("%d",&k2);
                s=search(x,k2);
                if(s==NULL || (predecessor(s))==NULL) 
                {
                    printf("NotFound\n");
                    break;
                }
                printf("%d\n",((predecessor(s)))->key);
                break;
            case 'd':
                scanf("%d",&k3);
                d=search(x,k3);
                if(d==NULL)
                {
                    printf("NotFound\n");
                    break;
                }
                printf("%d\n",k3);
                x=del(x,k3);
                break;
            case 'p':
                preorder(x);
                printf("\n");
                break;
            case 'e': exit(0);
            default:break;
        }
    }
    return 0;
}
