//FormAI DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[] = {5, 10, 3, 8, 2, 7, 1, 9, 4, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    int temp, i, j, k, h;
    printf("Welcome to the puzzling sorting program!\n");
    printf("Here is the unsorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n\n");

    printf("To start the sorting process, let's first try the Bubble Sort algorithm.\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    printf("After applying Bubble Sort algorithm:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n\n");
    
    printf("Next up, let's try the Selection Sort algorithm.\n");
    for (i = 0; i < size - 1; i++) {
        k = i;
        for (j = i + 1; j < size; j++) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        temp = nums[k];
        nums[k] = nums[i];
        nums[i] = temp;
    }
    printf("After applying Selection Sort algorithm:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n\n");

    printf("Last but not least, let's try the Shell Sort algorithm.\n");
    for (h = size/2; h > 0; h /= 2) {
        for (i = h; i < size; i++) {
            temp = nums[i];
            for (j = i; j >= h && nums[j-h] > temp; j -= h) {
                nums[j] = nums[j-h];
            }
            nums[j] = temp;
        }
    }
    printf("After applying Shell Sort algorithm:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n\n");
    printf("Thank you for trying out this puzzling sorting program!\n\n");

    return 0;
}