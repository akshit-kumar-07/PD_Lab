#include <stdio.h>
#include <stdlib.h>
struct node
{
	int key;
	struct node *next;
	struct node *prev;
};

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



struct node* create_node(int data)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->key=data;
	tmp->next=NULL;
	tmp->prev=NULL;
	return tmp;
}

void swap(struct node **x,struct node **y)
{
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->key=(*x)->key;
	(*x)->key=(*y)->key;
	(*y)->key=tmp->key;
	return;
}

void list_insert_front(struct node **head,int data)
{
	struct node *tmp=create_node(data);
	tmp->next=(*head);
	if(*head!=NULL)
		((*head)->prev)=tmp;
	(*head)=tmp;
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
	
	return;
}

void print_list(struct node *head)
{
	if(head==NULL)
	{
		printf("NULL\n");
		return;
	}
	int n=0;
	struct node *temp=head;
	while(temp->next!=NULL)
				{
					n++;temp=temp->next;
				}
				n++;
	int arr[n];int count=0;
	struct node *last=head;
	while(last->next!=NULL)last=last->next;
	struct node *p=head;
	while(p!=NULL) 
	{
		//printf("%d ",p->key);
		arr[count++]=p->key;
		p=p->next;
	}
	for(int i=n-1;i>=0;i--)
		printf("%d ",arr[i]);
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
			case 'p':
				if(head==NULL)
				{
					printf("NULL\n");
					break;
				}
				int x;int y;int n=0;scanf("%d %d",&x,&y);
				//printf("x=%d y=%d\n",x,y);
				struct node *x1,*x2,*temp;
				x1=head;temp=head;
				while(temp->next!=NULL)
				{
					//printf("n=%d %d ",n,temp->key);
					n++;temp=temp->next;
				}
				//printf("\n");
				n++;x2=head;
				//printf("n=%d\n",n);
				for(int i=1;i<x;i++)
					x1=x1->next;
				for(int i=0;i<n-y;i++)
					x2=x2->next;
				//printf("%d %d\n",x1->key,x2->key);
				swap(&x1,&x2);
				print_list(head);
				n=0;
				break;
			case 'r':
				print_list(head);				
				break;
			case 'e':
				return 0;
			default:
				break;
		}
	}
	return 0;
}
