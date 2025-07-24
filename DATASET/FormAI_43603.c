//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int search(int arr[], int n, int x)
{
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int n, x, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    int result = search(arr, n, x);
    if(result == -1){
        printf("Element not found\n");
    }else{
        printf("Element found at index %d\n",result);
    }
    return 0;
}