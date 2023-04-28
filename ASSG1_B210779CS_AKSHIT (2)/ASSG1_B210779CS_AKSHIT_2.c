#include <stdio.h>
#define li long int
#define rep(i,a,b) for(int i=a;i<b;i++)
void acw_rot(int arr[],int ans[],int d,int len)
{
    int eff=d%len;
    int x=eff;int cntr=0;
    rep(i,x,len)
    {
        ans[cntr++]=arr[i];
    }
    rep(i,0,eff)
    {
        ans[cntr++]=arr[i];
    }
}
int main()
{
    int n=0;
    scanf("%d",&n);
    int arr[n];
    int ans[n];
    rep(i,0,n)
    {
        scanf("%d",&arr[i]);
    }
    int m;
    scanf("%d",&m);
    acw_rot(arr,ans,m,n);
    rep(i,0,n)
    {
        printf("%d ",ans[i]);
    }
}