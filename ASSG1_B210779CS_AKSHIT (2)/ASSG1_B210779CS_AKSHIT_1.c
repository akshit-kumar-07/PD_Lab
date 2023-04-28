#include <stdio.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
void digit(int arr[],int num)
{
    int ind=0;
    while(num)
    {
        arr[ind++]=num%10;
        num/=10;
    }
}
ll POWER(int num,int exp)
{
    if(num==0&&exp==0)
    {
        return 1;
    }
    if (exp != 0)
        return (num * POWER(num, exp - 1));
    else
        return 1;
}
ll summation(int arr[],int exp)
{
    ll sum=0;
    rep(i,0,5)
    {
        ll x=POWER(arr[i],exp);
        sum+=x;
    }
    return sum;
}
int main()
{
    int number;int exponent;
    scanf("%d %d",&number,&exponent);
    int arr[5]={0,0,0,0,0};
    digit(arr,number);
    
    ll sum=summation(arr,exponent);
    printf("%lld",sum);
}