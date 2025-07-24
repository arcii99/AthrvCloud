//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include<stdio.h>
int main()
{
    int n,i,j,temp;
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of the array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nOriginal Array : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nSorted Array : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}