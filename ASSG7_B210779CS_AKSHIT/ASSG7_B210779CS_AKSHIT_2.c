#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char key;
    struct node *next;
    struct node *left;
    struct node *right;
};
struct node* new_node(char k)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->next=NULL;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->key=k;
    return tmp;
}
void inorder(struct node *x)
{
    if(x==NULL) return;
    inorder(x->left);
    printf("%c",x->key);
    inorder(x->right);
}
void preorder(struct node *x)
{
    if(x==NULL) return;
    printf("%c",x->key);
    preorder(x->left);
    preorder(x->right);
}
void postorder(struct node *x)
{
    if(x==NULL) return;
    postorder(x->left);
    postorder(x->right);
    printf("%c",x->key);
}
void push(struct node **head,char k)
{
    struct node *tmp=new_node(k);
    if(*head==NULL)
    {   (*head)=tmp;return;}
    tmp->next=(*head);
    (*head)=tmp;
    return;
}
void push_node(struct node **head,struct node *x)
{
    if((*head)==NULL)
    {
        (*head)=x;return;
    }
    x->next=*head;
    *head=x;
}
struct node* pop(struct node **head)
{
    struct node *p=(*head);
    (*head)=(*head)->next;
    return p;
}
void expression_tree(struct node **tree,char *exp)
{
    int l=strlen(exp);
    struct node *x,*y,*tmp;
    for(int i=0;i<l;i++)
    {
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            (tmp)=new_node(exp[i]);
            x=pop(tree);
            y=pop(tree);
            (tmp)->left=y;
            (tmp)->right=x;
            push_node(tree,tmp);
        }
        else
        {
            tmp=new_node(exp[i]);
            push_node(tree,tmp);
        }
    }
}
int main()
{
    char ch;char exp[100000];
    struct node *head=NULL;
    while(1)
    {
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'e':
                scanf("%s",exp);//printf("%s\n",exp);
                expression_tree(&head,exp);
                break;
            case 'i':
                inorder(head);printf("\n");
                break;
            case 'p':
                preorder(head);printf("\n");
                break;
            case 's':
                postorder(head);printf("\n");
                break;
            case 't':
                return 0;
            default:break;
        }
    }
    return 0;
}
