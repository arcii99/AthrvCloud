//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include<stdio.h>

int main()
{
    int n, sum=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d elements: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray elements:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");

    int min1=arr[0], min2=arr[1];
    if(min2<min1)
    {
        min1=arr[1];
        min2=arr[0];
    }
    for(int i=2;i<n;i++)
    {
        if(arr[i]<min1)
        {
            min2=min1;
            min1=arr[i];
        }
        else if(arr[i]<min2)
        {
            min2=arr[i];
        }
    }
    printf("Minimum two elements: %d %d\n",min1,min2);
    printf("Their sum: %d\n",min1+min2);

    return 0;
}