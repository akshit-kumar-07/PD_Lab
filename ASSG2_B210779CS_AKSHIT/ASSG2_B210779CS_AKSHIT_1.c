#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define new printf("\n")
int main()
{
    int index[26]={0};
    int count=0;int product=1;
    char string[1000]={'\0'};
    scanf("%s",string);
    for(int i=0;string[i]!='\0';i++)
    {
        int x=(int)string[i]-97;
        index[x]++;
    }
    rep(i,0,25)
    {
        //printf("%d ",index[i]);
        //new;
        if(index[i]!=0)
        {
            product=index[i]*product;
        }
    }
    printf("%d",product);
    return 0;
}