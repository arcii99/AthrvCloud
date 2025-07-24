//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int shockingSearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int middle;
    
    while (left <= right) {
        middle = (left + right) / 2;
        
        if (arr[middle] == target) {
            printf("OMG! Target found at index %d!\n", middle);
            return middle;
        }
        else if (arr[middle] < target) {
            printf("WOW! Moving right...\n");
            left = middle + 1;
        }
        else {
            printf("WHAT! Moving left...\n");
            right = middle - 1;
        }
    }
    
    printf("NO WAY! Target not found.\n");
    return -1;
}

int main() {
    int arr[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;
    
    printf("Let's see if we can find %d...\n", target);
    shockingSearch(arr, n, target);
    
    target = 22;
    printf("What about %d?...\n", target);
    shockingSearch(arr, n, target);
    
    return 0;
}