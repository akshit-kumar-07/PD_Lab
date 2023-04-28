#include <stdio.h>
#include <stdlib.h>
#define rep(i, a, b) for (int i = 0; i < b; i++)
int size = 0;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int parent(int i)
{
    return (i - 1) / 2;
}

int left(int i)
{
    return (2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}
int get_next_process(int arr[])
{
    if (size == 0)
        return -1;
    return arr[0];
}
void insert_process(int arr[], int key)
{
    size++;
    arr[size - 1] = key;
    int x = size - 1;
    while (x > 0 && arr[parent(x)] > arr[x])
    {
        /*int temp = arr[parent(x)];
        arr[parent(x)] =arr[x];
        arr[x] = temp;*/
        swap(&arr[x], &arr[parent(x)]);
        x = parent(x);
    }
}
void min_heapify(int arr[], int i)
{
    int smallest = i;
    // int left = 2 * i + 1;
    // int right = 2 * i + 2;
    if (left(i) < size && arr[smallest] > arr[left(i)])
        smallest = left(i);
    if (right(i) < size && arr[smallest] > arr[right(i)])
        smallest = right(i);
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        min_heapify(arr, smallest);
    }
}
int extract_next_process(int arr[])
{
    if (size == 0)
        return -1;
    int last = arr[size - 1];
    int res = arr[0];
    swap(&arr[0], &last);
    size--;
    min_heapify(arr, 0);
    return res;
}
void change_priority(int arr[], int k, int x)
{
    if (x > k)
        return;
    int ind = 0;
    rep(i, 0, size)
    {
        if (arr[i] == k)
        {
            ind = i;
            break;
        }
    }
    arr[ind] = x;
    while (ind > 0 && arr[parent(ind)] > arr[ind])
    {
        swap(&arr[ind], &arr[parent(ind)]);
        ind = parent(ind);
    }
}
void display(int arr[])
{
    rep(i, 0, size)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[1000] = {0};
    char ch;
    int key = 0;
    int old = 0;
    int x = 0;
    while (1)
    {
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'i':
            scanf("%d", &key);
            insert_process(arr, key);
            break;
        case 'd':
            display(arr);
            break;
        case 'e':
            printf("%d\n", extract_next_process(arr));
            break;
        case 'm':
            printf("%d\n", get_next_process(arr));
            break;
        case 'c':
            scanf("%d %d", &old, &x);
            change_priority(arr, old, x);
            break;
        case 's':
            return -1;
        }
    }
    return 0;
}