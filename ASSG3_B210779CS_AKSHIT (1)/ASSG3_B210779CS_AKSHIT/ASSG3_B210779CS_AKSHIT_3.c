#include<stdio.h>
#include<stdlib.h>
int length(char str[])
{
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;
}
int compare(char str1[],char str2[])
{
    int n=0;int m=0;
    n=length(str1);
    m=length(str2);
    int i=0;int j=0;
    while(i<n && j<m)
    {
        if((int)str1[i]>(int)str2[j])
            return 1;
        if((int)str1[i]<(int)str2[j])
            return -1;
        i++;j++;
    }
    return 0;
}
void cpy(char *str2, char *str1)
{
    int i;
    for(i=0;str1[i] != '\0';i++){
        str2[i] =str1[i];
    }
    str2[i] = '\0';
}
void Merge(char* arr[],int lower,int mid,int upper) 
{
    int n1= mid-lower+1;
    int n2= upper-mid;

    char** left_arr=(char **)malloc(sizeof(char *)*n1);
    char** right_arr=(char **)malloc(sizeof(char *)*n2);
    int i;
    for(i=0;i<n1;i++)
    {
        left_arr[i]=(char *)malloc(sizeof(arr[lower+i]));
        cpy(left_arr[i],arr[lower+i]);
    }
    for(i=0;i<n2;i++)
    {
        right_arr[i]=(char *)malloc(sizeof(arr[mid+i+1]));
        cpy(right_arr[i],arr[mid+i+1]);
    }
    i=0;int j=0;int k=lower;
    while(i<n1&&j<n2)
    {
        if(compare(left_arr[i],right_arr[j])<0){
            cpy(arr[k],left_arr[i]);
            i++;
        }
        else {
            cpy(arr[k],right_arr[j]);
            j++;
        }
        k++;
    }
    while(i<n1)cpy(arr[k++],left_arr[i++]);
    while(j<n2)cpy(arr[k++],right_arr[j++]);

}


void MergeSort(char* arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char** arr=(char **)malloc(sizeof(char *)* n);
    int i;
    for(i=0;i<n;i++)
    {
        arr[i]=(char *)malloc(sizeof(char)*100);
        scanf("%[^\n]",arr[i]);
        getchar();
    }
    MergeSort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf("%s",arr[i]);
	if(i!=n-1)
		printf("\n");
    }
    return 0;

}