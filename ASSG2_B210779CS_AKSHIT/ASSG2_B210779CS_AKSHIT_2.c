#include <stdio.h>
int checker(int arr[],int n,int size,int key)
{
    int count=0;
    for(int i=0;i<n;i+=size)
    {
        int flag=-1;
        //printf("%d ",i);
        for(int j=i;(j<i+size)&&(flag==-1);j++)
        {
            if(arr[j]==key)
            {
                //printf("%d %d\n",i,j);
                flag=0;
                count++;
            }
        }
        
    }
    return count;
}
int main()
{
    int n=0;int k=0;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int t;scanf("%d",&t);
    int count=checker(arr,n,k,t);
    printf("%d\n",count);
    return 0;
}