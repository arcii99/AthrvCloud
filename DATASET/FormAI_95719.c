//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>

int main() {
    printf("I am so excited to show you my unique C searching algorithm!\n");
    int arr[10] = {1, 4, 7, 9, 11, 12, 15, 17, 20, 22};
    int searchValue = 12;
    int leftIndex = 0;
    int rightIndex = sizeof(arr)/sizeof(int) - 1;
    int midIndex;

    printf("Let's search for the value %d in the array:\n", searchValue);
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while(leftIndex <= rightIndex) {
        midIndex = (leftIndex + rightIndex) / 2;

        if(searchValue == arr[midIndex]) {
            printf("Found %d at index %d!\n", searchValue, midIndex);
            return 0;
        }

        if(searchValue < arr[midIndex]) {
            rightIndex = midIndex - 1;
        } else {
            leftIndex = midIndex + 1;
        }
    }

    printf("Did not find %d in the array.\n", searchValue);
    return 0;
}