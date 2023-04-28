#include <stdio.h>
#include <stdlib.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
void swap(float *a,float *b)
{
    float t=*a;
    *a=*b;
    *b=t;
}
void max_heapify(float arr[],int n,int i)
{
    int largest=i;int left=2*i+1;int right=2*i+2;
    if(left<n && arr[largest]<arr[left])
        largest=left;
    if(right<n && arr[largest]<arr[right])
        largest=right;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        max_heapify(arr,n,largest);
    }
}
void build_max_heap(float arr[],int n)
{
    for(int i=n/2;i>=0;i--)
        max_heapify(arr,n,i);
}
void heap_sort(float arr[],int n)
{
    build_max_heap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        max_heapify(arr,i,0);
    }
}
int main()
{
    int n=0;int k=0;
    scanf("%d %d",&n,&k);
    float arr[n];
    rep(i,0,n)
        scanf("%f",&arr[i]);
    int g=n/k;
    float cap[g];int cntr=0;
    for(int i=0;i<n;i+=k)
    {
        float *temp=(float *)(malloc(sizeof(float)*n));
        rep(j,i,i+k)
            temp[j-i]=arr[j];
        heap_sort(temp,k);
        cap[cntr++]=temp[k-1];
        /*rep(j,0,k)
            printf("%0.2f ",temp[j]);
        printf("\n");*/
        free(temp);
    }
    rep(i,0,cntr)
        printf("%0.2f ",cap[i]);
    return 0;
}