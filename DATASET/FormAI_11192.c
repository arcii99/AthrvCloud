//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int linear_search(int *arr, int n, int key) 
{
    int i;
    for(i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, key, index, i;
    int *arr;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(sizeof(int)*n);
    
    printf("Enter elements of array: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter key to search: ");
    scanf("%d", &key);
    
    index = linear_search(arr, n, key);
    
    if(index < 0) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d\n", index);
    }
    
    free(arr);
    
    return 0;
}