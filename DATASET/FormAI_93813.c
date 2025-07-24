//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include<stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    printf("Welcome to the Binary Search Program!\n");
    printf("This program searches for a specific target in an array.\n");

    int arr[] = {1, 4, 7, 8, 10, 15, 18, 22, 24, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nThe Example Array is: {1, 4, 7, 8, 10, 15, 18, 22, 24, 28}\n");
  
    int target;
    printf("\nWhat number are you searching for? ");
    scanf("%d", &target);
  
    int result = binarySearch(arr, 0, n - 1, target);
  
    if (result == -1)
        printf("\nTarget number %d is not in the Example Array.\n", target);
    else
        printf("\nTarget number %d is at array index %d.\n", target, result);

    return 0;
}