//FormAI DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int search(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    printf("Welcome to the mysterious searching algorithm!\n");
    printf("To begin, you must enter the size of your array: ");
    int size;
    scanf("%d", &size);
    printf("Excellent choice! Now enter your %d integers: ", size);
    
    int array[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Well done, now for the thrilling part...\n");
    printf("Please enter the number you would like to search for: ");
    int target;
    scanf("%d", &target);
    
    int result = search(array, size, target);
    
    if (result == -1) {
        printf("Unfortunately, your target could not be found.\n");
    } else {
        printf("Congratulations, your target was found at index %d!\n", result);
    }
    printf("Thank you for participating in the mysterious searching algorithm!\n");
    return 0;
}