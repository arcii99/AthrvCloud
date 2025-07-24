//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

int braveSearch(int arr[], int size, int target) {
    int i = 0;
    while (i < size) {
        if (arr[i] == target) {
            printf("I found it! The target %d was at position %d.\n", target, i+1);
            return i;
        }
        else {
            printf("I didn't find it at position %d.\n", i+1);
            i++;
        }
    }
    printf("Oh no! The target wasn't found in the array.\n");
    return -1;
}

int main() {
    int array[10] = {22, 10, 33, 99, 55, 44, 77, 66, 88, 11};
    int target = 55;
    int result = braveSearch(array, 10, target);
    return 0;
}