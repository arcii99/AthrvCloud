//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

/* Futuristic C Searching Algorithm */

int futuristic_search(int array[], int size, int target) {
    int start = 0, end = size - 1, mid;
    
    while(start <= end) {
        mid = (start + end) / 2;
        
        if(array[mid] == target) {
            printf("Target found at index %d\n", mid);
            return mid;
        }
        
        if(array[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    printf("Target not found in array.\n");
    return -1;
}

/* Main Program */

int main() {
    int array[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int size = sizeof(array) / sizeof(array[0]);
    
    printf("Array: ");
    for(int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    int target = 35;
    
    printf("Target: %d\n", target);
    
    int result = futuristic_search(array, size, target);
    
    return 0;
}