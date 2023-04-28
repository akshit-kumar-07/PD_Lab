#include <stdio.h>
#define new printf("\n");
#define rep(i, a, b) for (int i = a; i < b; i++)
void insertion_sort(float arr[], int n)
{
    int i = 0;
    int j = 0;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        float key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void copy_arr(float arr1[], float arr2[], int n)
{
    rep(i, 0, n)
    {
        arr2[i] = arr1[i];
    }
}
int bsearch(float arr[], int lower, int upper, float key)
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
    int n;
    scanf("%d", &n);
    float arr[n];
    rep(i, 0, n)
        scanf("%f", &arr[i]);
    float cpy[n];
    copy_arr(arr, cpy, n);
    insertion_sort(cpy, n);
    /*rep(i,0,n)
        printf("%d ",cpy[i]);
    new;
    int key;scanf("%d",&key);
    printf("%d\n",bsearch(cpy,0,n-1,key));
    /*insertion_sort(arr,n);
    rep(i,0,n)
        printf("%d ",arr[i]);
    new;*/
    rep(i, 0, n)
    {
        printf("%d ", bsearch(cpy, 0, n - 1, arr[i]));
    }
    return 0;
}