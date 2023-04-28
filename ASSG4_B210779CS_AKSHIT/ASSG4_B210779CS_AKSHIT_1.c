#include <stdio.h>
#include <string.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef struct
{
    char name[100];
    int marks;
} student;
void swap(student *a, student *b)
{
    student t = *a;
    *a = *b;
    *b = t;
}
void insert(student arr[], int pos, student key, int n)
{
    for (int j = pos; j < n - 1; j++)
    {
        swap(&arr[pos], &arr[j + 1]);
    }
}
void shift(student arr[], int n, int key)
{
    rep(i, key, n - 1)
    {
        swap(&arr[i], &arr[i + 1]);
    }
}
void partition(student arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high].marks;
    rep(j, low, high)
    {
        if (arr[j].marks < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // swap(&arr[i+1],&arr[high]);
    insert(arr, i + 1, arr[high], high - low + 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    student arr[n];
    rep(i, 0, n)
    {
        scanf("%s %d", arr[i].name, &arr[i].marks);
    }
    char cr[31];
    scanf("%s", cr);
    int key = 0;
    rep(i, 0, n)
    {
        if (strcmp(arr[i].name, cr) == 0)
            key = i;
    }
    shift(arr, n, key);
    partition(arr, 0, n - 1);
    rep(i, 0, n)
    {
        printf("%s ", arr[i].name);
    }
    return 0;
}