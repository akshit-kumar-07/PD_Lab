#include <stdio.h>
#define ll long long
ll length(char str[])
{
    ll sum=0;
   for(ll i=0;str[i]!='\0';i++)
   {
      sum++;
   }
   return sum;
}
void to_lower(char str[])
{
   for(ll i=0;str[i]!='\0';i++){
      if((str[i]>=65)&&(str[i]<=90))
      {
         str[i]=str[i]+32;
      }
   }
}
void reverse(char str1[],char str2[],ll n)
{
   for(ll i=0;i<n;i++)
   {
      str2[i]=str1[n-i-1];
   }
}
void is_pal(char str1[],char str2[],ll n)
{
    int flag=0;
   for(ll i=0;i<n;i++)
   {
      if (str1[i]==str2[i])
      {
         //printf("%c %c\n",str1[i],str2[n-i-1]);
         flag=0;
      }
      else
      {
         flag=-1;
         break;
      }
   }
   (flag==0)?(printf("YES\n")):(printf("NO\n"));
}
int main()
{
    char str[1000000]={'\0'};
    scanf(" %s",str);
    ll len=length(str);
    to_lower(str);
    //printf("%d",len);
    //printf("%s",str);
    char bfr[len+1];
    bfr[len]='\0';
    reverse(str,bfr,len);
    //printf("%s\n",bfr);
    is_pal(str,bfr,len);
    return 0;
}