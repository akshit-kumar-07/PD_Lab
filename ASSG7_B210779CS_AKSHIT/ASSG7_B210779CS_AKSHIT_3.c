#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
int peek(stack* s)
{
    return s->arr[s->top];
}
int evalpos(char *exp)
{
    int len=strlen(exp);
    stack *s=new_stack(len);
    char *pos=(char *)malloc(sizeof(char)*len);
    char x;char temp;
    for(int i=0;i<len;i++)
    {
        if(exp[i]==' ')continue;
        x=exp[i];
        if(x>='0' && x<='9')
            //push(&s,(int)(x-'0'));
        {
            int num=0;
            while(isdigit(exp[i]))
            {
                //char x=exp[i];
                num=num*10 + (int)(exp[i]-'0');
                i++;
            }
            i--;
            push(&s,num);
        }
        else
        {
            char a=pop(&s);
            char b=pop(&s);
            switch(x)
            {
                case '+':
                    temp=b+a;
                    break;
                case '-':
                    temp=b-a;
                    break;
                case '*':
                    temp=b*a;
                    break;
                case '/':
                    temp=b/a;
                    break;
                default:break;
                
            }
            push(&s,temp);
        }
    }
    int res=pop(&s);
    return res;
}
int main()
{
    int n;scanf("%d",&n);getchar();
    while(n--)
    {
        char exp[100000];
        //gets(exp,100000,stdin);
        //printff
        scanf("%[^\n]s",exp);getchar();
        printf("%d\n",evalpos(exp));
    }
    return 0;
}
