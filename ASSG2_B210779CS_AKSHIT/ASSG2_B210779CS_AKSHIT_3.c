#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define new printf("\n")
int second_largest(int arr[],int n)
{
    int max=0,s_max=0;
    rep(i,0,n)
    {
        if(arr[i]>max&&arr[i]>s_max)
            max=arr[i];
        else if(arr[i]<max&&arr[i]>s_max)
            s_max=arr[i];
    }  
    return s_max; 
}
int del(int arr[],int n,int key)
{
    rep(i,0,n)
    {
        if(arr[i]==key)
        {
            arr[i]=-9999;
        }
    }
    return 0;
}
void print_arr(int arr[],int n)
{
    rep(i,0,n)
    {
        if (arr[i]!=-9999)
            printf("%d ",arr[i]);
    }
    new;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    rep(i,0,n){scanf("%d",&arr[i]);}
    int mex=second_largest(arr,n);
    del(arr,n,mex);
    print_arr(arr,n);
    return 0;
}