//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Exciting Linear Search Algorithm

int linear_search(int arr[], int n, int target)
{
    int i;
    for(i=0;i<n;i++){ 
        if(target==arr[i]){
            printf("Yay! Found the target at index %d.",i);
            return i;
        }
    }
    printf("Oops! The target is not found.");
    return -1;
}

int main()
{
    int arr[10] = {5, 9, 20, 30, 55, 61, 70, 80, 90, 99};
    int target, res;
    printf("Welcome to the Exciting Linear Search Algorithm!\n");
    printf("Enter the target you want to find: ");
    scanf("%d", &target);
    res = linear_search(arr, 10, target);
    return 0;
}