#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    int top;
    int cap;
    char *arr;
}stack;
stack* new_stack(int n)
{
    stack *tmp=(stack *)malloc(sizeof(stack));
    tmp->top=-1;
    tmp->cap=n;
    tmp->arr=(char *)malloc(sizeof(char));
    return tmp;
}
int is_empty(stack *s)
{
    return(s->top==-1);
}
int is_full(stack *s)
{
    return (s->top==s->cap-1);
}
void push(stack **s,char k)
{
    if(is_full(*s))
        return ;
    (*s)->arr[++(*s)->top]=k;
}
char pop(stack **s)
{
    if(is_empty(*s))
        return '\0';
    return((*s)->arr[(*s)->top--]);
}
int Prec(char ch)
{
    switch (ch) 
    {
    case '(':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
 
    case '*':
        return 2;
    case '/':
        return 2;
 
    default:return 0;
    }
    return -1;
}
char peek(stack* s)
{
    return s->arr[s->top];
}
void inf2pos(char *exp)
{
    stack *s=new_stack(strlen(exp));
    char *pos=(char *)malloc(sizeof(char)*strlen(exp));
    char x;char k=0;char t;
    for(int i=0;i<strlen(exp);i++)
    {
        x=exp[i];
        switch(x)
        {
            case '(':
                push(&s,x);
                break;
            case ')':
                while(!(is_empty(s))&&(t=pop(&s))!='(')
                    pos[k++]=t;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(!is_empty(s)&&Prec(x)<=Prec(peek(s)))
                    pos[k++]=pop(&s);
                push(&s,x);
                break;
            default:
                pos[k++]=x;
                break;
        }
    }
    while(!is_empty(s))
        pos[k++]=pop(&s);
    pos[k++]='\0';
    for(int i=0;i<strlen(pos);i++)
        printf("%c",pos[i]);
    printf("\n");
    return;
}
int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        char exp[100000];
        scanf("%s",exp);
        inf2pos(exp);
    }
    return 0;
}

