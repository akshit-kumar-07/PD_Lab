
#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void max_heapify(int arr[],int n,int i,int *c)
{
    int largest=i;int left=2*i+1;int right=2*i+2;
    if(left<n){
        (*c)++;
    }
    if(left<n && arr[largest]<arr[left])
        largest=left;

    if(right<n){
        (*c)++;
    }    
    if(right<n && arr[largest]<arr[right])
        largest=right;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        max_heapify(arr,n,largest,c);
    }
}
void build_max_heap(int arr[],int n,int *c)
{
    for(int i=n/2;i>=0;i--)
        max_heapify(arr,n,i,c);
}
void heap_sort(int arr[],int n,int *c)
{
    build_max_heap(arr,n,c);
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        max_heapify(arr,i,0,c);
    }
}
int main()
{
    int count=0;int *c=&count;
    int n;scanf("%d",&n);
    int arr[n];
    rep(i,0,n)
        scanf("%d",&arr[i]);
    heap_sort(arr,n,c);
    rep(i,0,n)
        printf("%d ",arr[i]);
    printf("\n%d",count);
    return 0;
}