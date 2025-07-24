//FormAI DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>

int find_value(int array[], int size, int value) {
    int lower_bound = 0;
    int upper_bound = size - 1;
    while (lower_bound <= upper_bound) {
        int middle = (lower_bound + upper_bound) / 2;
        if (array[middle] == value) {
            return middle;
        }
        if (array[middle] < value) {
            lower_bound = middle + 1;
        } else {
            upper_bound = middle - 1;
        }
    }
    return -1;
}

int main() {
    int array[10] = {2, 3, 4, 5, 7, 9, 11, 13, 17, 19};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Searching for value 7 in a post-apocalyptic world...\n");
    int index = find_value(array, size, 7);
    if (index != -1) {
        printf("Value 7 found at index %d\n", index);
    } else {
        printf("Value 7 not found\n");
    }
    return 0;
}