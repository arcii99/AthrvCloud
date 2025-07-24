//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

int linear_search(int arr[], int num, int key) {

    int i; 

    for (i = 0; i < num; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {

    int num, i, key, arr[100], position;

    printf("\nPlease enter the size of the array: ");
    scanf("%d", &num);

    printf("\nPlease enter the elements of the array:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nPlease enter the search key: ");
    scanf("%d", &key);

    position = linear_search(arr, num, key);

    if (position == -1) {
        printf("\nThe search key is not present in the array.\n");
    } 
    else {
        printf("\nThe search key is present at index: %d\n", position);
    }

    return 0;
}