#include <stdio.h>
#include <stdlib.h>
#define new printf("\n")
#define rep(i,a,b) for(int i=a;i<b;i++)
void read(int arr[],int n)
{
    rep(i,0,n){
        scanf("%d",&arr[i]);}
    //printf("Inside Read\n");
    return;
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    new;
    return;
}
int digit_sum(int num)
{
    int sum=0;
    int cpy=num;
    int digit_arr[6]={0};
    int i=0;
    while(cpy)
    {
        digit_arr[i]=cpy%10;
        cpy=cpy/10;
        sum+=digit_arr[i];
        i++;
    }
    return sum;
}
void digit_sort(int arr[],int n)
{
    int i=0;int j=0;
    rep(i,1,n)
    {
        j=i-1;
        int key=arr[i];
        while(j>=0 && digit_sum(arr[j])>digit_sum(key))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(void) 
{
	int n;
    char ch;
    scanf(" %c %d",&ch,&n);
    int arr[n];
    while(ch!='t'&&n!=0)
    {
        //printf("%c\n",ch);
        if(ch=='r')
            read(arr,n);
        if(ch=='p')
            print(arr,n);
        if(ch=='d')
        {
            int ind;
            scanf("%d",&ind);
            printf("%d\n",digit_sum(arr[ind]));
        }
        if(ch=='s')
        {
            digit_sort(arr,n);
        }
        if(ch=='t')
        {
            printf("-1");
            break;
        }
        scanf(" %c",&ch);
    }
    printf("-1");
	return 0;
}

