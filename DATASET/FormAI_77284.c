//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
// Welcome to my custom sorting algorithm!

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, temp;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);

    int arr[n]; // dynamic array allocation

    printf("Enter %d integer values:\n", n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Unsorted Array:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    // Sorting Algorithm Begins
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    printf("\n\nSorted Array:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}