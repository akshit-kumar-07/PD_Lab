#include <stdio.h>
#include <stdlib.h>
struct node
{
	int key;
	struct node *next;
	struct node *prev;
};

struct node* create_node(int data)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->key=data;
	tmp->next=NULL;
	tmp->prev=NULL;
	return tmp;
}
int count=0;
void list_insert_front(struct node **head,int data)
{
	struct node *tmp=create_node(data);
	tmp->next=(*head);
	if(*head!=NULL)
		((*head)->prev)=tmp;
	(*head)=tmp;
	count++;
}

void list_insert_tail(struct node **head,int data)
{
	struct node *tmp=create_node(data);
	struct node *p=*head;
	if(*head==NULL)
	{
		tmp->next=*head;
		*head=tmp;
		return;
	}
	while(p->next!=NULL) p=p->next;
	p->next=tmp;
	tmp->prev=tmp;
	count++;
	return;
}

struct node* list_search(struct node *head,int data)
{
	struct node *p=head;
	while(p!=NULL) 
	{
		if(p->key==data)
			return p;
		p=p->next;
	}
	return NULL;
}

void list_insert_after(struct node **head,int data,int ind)
{
	if(*head==NULL)
	{
		printf("NULL\n");
		return;
	}
	struct node *after=list_search(*head,ind);
	if(after==NULL)
	{
		printf("ABSENT\n");
		return;
	}
	struct node *tmp=create_node(data);
	struct node *p=after->next;
	p->prev=tmp;
	tmp->next=p;
	after->next=tmp;
	tmp->prev=after;count++;
	return;
}

void list_insert_before(struct node **head,int data,int ind)
{
	if(*head==NULL)
	{
		printf("NULL\n");
		return;
	}
	struct node *b4=list_search(*head,ind);
	if(b4==NULL)
	{
		printf("ABSENT\n");
		return;
	}
	struct node *tmp=create_node(data);
	struct node *p=b4->prev;
	p->next=tmp;
	tmp->prev=p;
	b4->prev=tmp;
	tmp->next=b4;count++;
	return;
}

void  list_delete_first(struct node **head)
{
	struct node *tmp;
	if(*head==NULL)
	{
		printf("NULL");
		return;
	}
	tmp=*head;
	(*head)=(*head)->next;
	(*head)->prev=NULL;
	printf("%d\n",tmp->key);
	free(tmp);
	return;
}

void list_delete_last(struct node **head)
{
	if(*head==NULL)
	{
		printf("NULL");
		return;
	}
	struct node *tmp;struct node *p=*head;
	while(p->next->next!=NULL) p=p->next;
	tmp=p->next;
	p->next=NULL;
	printf("%d\n",tmp->key);
	free(tmp);
	return;
}

void list_delete(struct node **head,int k)
{
	
	if(*head==NULL || count==0)
	{
		printf("NULL\n");
		return;
	}
	struct node *del=list_search(*head,k);
	if(del==NULL)
	{
		printf("ABSENT\n");
		return;
	}
	if(del==*head)
	{
		printf("FIRST\n");
		*head=(*head)->next;
	}
	if(del->next!=NULL)
	{
		printf("%d\n",del->prev->key);
		del->next->prev=del->prev;
	}
	if(del->prev!=NULL)
	{
		printf("%d\n",del->prev->key);		
		del->prev->next=del->next;
	}
	free(del);
	return;
}

void print_list(struct node *head)
{
	struct node *last=head;
	while(last->next!=NULL)last=last->next;
	struct node *p=head;
	while(p!=NULL) 
	{
		printf("%d ",p->key);
		p=p->next;
	}
	printf("\n");
	return;
}

void print_reverse(struct node *head,int n)
{
	if(head==NULL)
	{
		printf("NULL\n");
		return;
	}
	struct node *check=list_search(head,n);
	if(check==NULL)
	{
		printf("ABSENT\n");
		return;
	}
	while(check!=NULL) 
	{
		printf("%d ",check->key);
		check=check->prev;
	}
	printf("\n");
	return;
}

int main()
{
	struct node *head=NULL;
	char c;
	while(1)
	{
		scanf(" %c",&c);
		switch(c)
		{
			case 'f':
				int k1;scanf("%d",&k1);
				list_insert_front(&head,k1);
				break;
			case 't':
				int k2;scanf("%d",&k2);
				list_insert_tail(&head,k2);
				break;
			case 'a':
				int k3;int k4;scanf("%d %d",&k3,&k4);
				list_insert_after(&head,k3,k4);
				break;
			case 'b':
				int k5;int k6;scanf("%d %d",&k5,&k6);
				list_insert_before(&head,k5,k6);
				break;
			case 'p':
				print_list(head);
				break;
			case 'i':
				list_delete_first(&head);
				break;
			case 'l':
				list_delete_last(&head);
				break;
			case 'd':
				int k7;scanf("%d",&k7);
				list_delete(&head,k7);
				break;
			case 'r':
				int k8;scanf("%d",&k8);
				print_reverse(head,k8);
				break;
			case 'e':
				return 0;
			default:
				break;
		}
	}
	return 0;
}
