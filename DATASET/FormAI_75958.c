//FormAI DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>

void binarySearch(int array[], int start, int end, int key) {
    int mid;
    
    while (start <= end) {
        mid = (start + end) / 2;
        
        if (array[mid] == key) {
            printf("The element is found at index %d.\n", mid);
            return;
        }
        
        else if (array[mid] < key)
            start = mid + 1;
            
        else
            end = mid - 1;
    }
    
    printf("The element is not found in the array.\n");
}

int main() {
    int array[] = {1, 3, 4, 5, 7, 9, 12, 15};
    int n = sizeof(array) / sizeof(array[0]);
    
    printf("Enter the element to be searched: ");
    int key;
    scanf("%d", &key);
    
    binarySearch(array, 0, n - 1, key);
    
    return 0;
}