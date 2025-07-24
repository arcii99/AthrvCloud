//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>

int search(int arr[10][10], int rows, int cols, int key) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == key) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int arr[10][10], rows, cols, i, j, key, found;
    printf("Enter number of rows (max 10): ");
    scanf("%d", &rows);

    printf("Enter number of columns (max 10): ");
    scanf("%d", &cols);

    printf("Enter elements of the array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter number to search: ");
    scanf("%d", &key);

    found = search(arr, rows, cols, key);

    if (found) {
        printf("%d found in the array!\n", key);
    } else {
        printf("%d not found in the array!\n", key);
    }

    return 0;
}