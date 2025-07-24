//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>

int main() {
    int nums[10] = {3, 4, 7, 2, 8, 1, 9, 5, 6, 0};
    int target = 7;
    int i, j, temp, count = 0;

    // bubble sort
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9-i; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    // binary search
    int left = 0, right = 9, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            printf("Target found at index %d\n", mid);
            count++;
            break;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (count == 0) {
        printf("Target not found in array\n");
    }

    return 0;
}