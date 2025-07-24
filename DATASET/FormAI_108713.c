//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>

int linear_search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int my_array[] = {2, 6, 4, 1, 8, 0, 9, 3};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    int value = 8;
    int index = linear_search(my_array, size, value);
    if (index != -1) {
        printf("Found %d at index %d\n", value, index);
    } else {
        printf("%d not found in array\n", value);
    }
    return 0;
}