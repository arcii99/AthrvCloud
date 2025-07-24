//FormAI DATASET v1.0 Category: Sorting ; Style: configurable
#include<stdio.h>

void bubble_sort(int arr[], int n, int order)
{
    int i, j, temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if((order==1 && arr[j]>arr[j+1]) || (order==-1 && arr[j]<arr[j+1]))
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n,order;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the desired sort order (1 for ascending order or -1 for descending order): ");
    scanf("%d",&order);

    bubble_sort(arr,n,order);

    printf("The sorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}