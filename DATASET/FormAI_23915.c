//FormAI DATASET v1.0 Category: Sorting ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,arr[100],j,temp;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("\nUnsorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\nSorting Started...\n");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

                printf("Swapped Elements : %d and %d\n",arr[i],arr[j]);
            }
        }
        printf("Iteration %d : ",i+1);
        for(int p=0;p<n;p++)
        {
            printf("%d ",arr[p]);
        }
        printf("\n");
    }

    printf("\nSorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}