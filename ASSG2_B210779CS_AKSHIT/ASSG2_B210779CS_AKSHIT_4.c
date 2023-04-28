#include <stdio.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define new printf("\n")
int bsearch(int arr[], int lower, int upper, int key)
{
    while(upper >= lower)
    {
        int mid = lower + (upper-lower)/2;
        if (arr[mid] == key)
            {
                return mid;
            }
        if (arr[mid] < key)
            {
                lower = mid + 1;
            }
        else
            {
                upper = mid - 1;
            }
    }
    return -1;
}
int main()
{
    int n = 0, t = 0;
    scanf("%d %d", &n, &t);
    int arr[n];
    rep(i, 0, n)
    {
        scanf("%d", &arr[i]);
    }
    int ind = 0;
    ind = bsearch(arr, 0, n-1, t);
    printf("%d\n", ind);

    if (ind == -1 || ind == n - 1)
    {
        printf("%d\n", -1);
    }
    else
    {
        rep(i, ind, n)
        {
            if (ind == -1)
            {
                printf("%d\n", -1);
            }
            if (arr[i] > t && ind != -1)
            {
                printf("%d ", i);
            }
        }
    }
    return 0;
}