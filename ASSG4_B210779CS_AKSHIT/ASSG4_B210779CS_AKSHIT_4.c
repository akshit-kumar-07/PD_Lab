#include <stdio.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef struct
{
    int key;
    int pos;
    int value;
} node;
void swap(node *a, node *b)
{
    node t = *a;
    *a = *b;
    *b = t;
}
void min_heapify(node arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[smallest].value > arr[left].value)
        smallest = left;
    if (right < n && arr[smallest].value > arr[right].value)
        smallest = right;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}
void build_min_heap(node arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        min_heapify(arr, n, i);
}
void heap_sort(node arr[], int n)
{
    build_min_heap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[0].value < arr[i].value)
        {
            swap(&arr[0], &arr[i]);
            min_heapify(arr, i, 0);
        }
    }
}
void insert(node arr[], int ps, int n, int x, int *c)
{
    // printf("Here\n");
    int i = 0;
    for (i = 0; i < ps; i++)
    {
        if (arr[i].key == x)
        {
            arr[i].value++;
            return;
        }
    }
    arr[*c].key = x;
    arr[*c].pos = (*c);
    (arr[*c].value)++;
    (*c)++;
    return;
}
int main()
{
    int n;
    int cntr = 0;
    int *c = &cntr;
    scanf("%d", &n);
    node arr[n];
    rep(i, 0, n)
        arr[i]
            .value = 0;
    rep(i, 0, n)
    {
        int x = 0;
        scanf("%d", &x);
        insert(arr, i, n, x, c);
    }
    /*rep(i, 0, cntr)
    {
        if (arr[i].value != 0)
            printf("%d %d %d %d\n", i, arr[i].key, arr[i].pos, arr[i].value);
    }*/
    // printf("---------------------------------------------%d--------------------------------\n", cntr);

    int k = 0;
    scanf("%d", &k);
    heap_sort(arr, cntr);
    /*rep(i, 0, cntr)
        printf("%d %d %d\n", arr[i].key, arr[i].pos, arr[i].value);*/
        
    for (int i = 0; i < k; i++)
        printf("%d ", arr[i].key);
    return 0;
}
