//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int binary_search(int arr[], int l, int r, int x);
void print_array(int arr[], int size);

int main() {
    int arr[SIZE] = {23, 45, 67, 89, 101, 123, 456, 789, 900, 987};
    int search = 101;

    printf("==========================================\n");
    printf("          Retro-Style Search Program      \n");
    printf("==========================================\n\n");

    print_array(arr, SIZE);

    printf("\nSearching for %d...\n", search);

    int index = binary_search(arr, 0, SIZE-1, search);

    if (index != -1) {
      printf("\n%d found at index %d\n", search, index);
    } else {
      printf("\n%d not found in the array\n", search);
    }

    printf("\n==========================================\n");
    printf("             End of Program               \n");
    printf("==========================================\n");

    return 0;
}

int binary_search(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binary_search(arr, l, mid - 1, x);
        }
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}

void print_array(int arr[], int size) {
    printf("Array: ");
    for (int i=0; i<size; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
}