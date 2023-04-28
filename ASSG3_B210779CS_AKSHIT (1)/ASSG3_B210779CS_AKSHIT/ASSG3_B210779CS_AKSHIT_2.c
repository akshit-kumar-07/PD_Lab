#include <stdio.h>
#define new printf("\n");
#define rep(i, a, b) for (int i = a; i < b; i++)
void merge(int arr1[],int arr2[],int arr[],int m,int n)
{
    int i=0;int j=0;int k=0;
    while(i<m&&j<n)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<m)
    {
        arr[k]=arr1[i];i++;k++;
    }
    while(j<n)
    {
        arr[k]=arr2[j];j++;k++;
    }
}
int bsearch(int arr[], int lower, int upper, int key)
{
    while (lower <= upper)
    {
        int mid = lower + (upper - lower) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return -1;
}
int main()
{
    int m;int n;
    scanf("%d %d",&m,&n);
    int arr1[m];int arr2[n];
    rep(i,0,m)
        scanf("%d",&arr1[i]);
    rep(i,0,n)
        scanf("%d",&arr2[i]);
    /*rep(i,0,m)
        printf("%d ",arr1[i]);
    new;
    rep(i,0,n)
        printf("%d ",arr2[i]);
    new;*/
    int arr[m+n];
    merge(arr1,arr2,arr,m,n);
    /*rep(i,0,n+m)
        printf("%d ",arr[i]);
    new;*/
    int target=0;scanf("%d",&target);
    printf("%d",bsearch(arr,0,n+m-1,target));
    return 0;
}