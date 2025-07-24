//FormAI DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#define MAX_SIZE 100

int search(int arr[], int length, int target)
{
    int i;
    for (i = 0; i < length; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    int arr[MAX_SIZE], length, target, i;
    
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    
    printf("Enter the elements of the array: ");
    for (i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    int pos = search(arr, length, target);
    
    if (pos == -1) {
        printf("%d is not found in the array.\n", target);
    }
    else {
        printf("%d is found at index %d.\n", target, pos);
    }
    
    return 0;
}