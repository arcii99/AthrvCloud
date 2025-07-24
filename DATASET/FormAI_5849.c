//FormAI DATASET v1.0 Category: Funny ; Style: single-threaded
#include <stdio.h>
#define MAX_NUM 10

int main() {
    int nums[MAX_NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, temp;

    printf("Before sorting:\n");
    for (i = 0; i < MAX_NUM; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Bubble sort
    for (i = 0; i < MAX_NUM - 1; i++) {
        for (j = 0; j < MAX_NUM - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    printf("After sorting:\n");
    for (i = 0; i < MAX_NUM; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}