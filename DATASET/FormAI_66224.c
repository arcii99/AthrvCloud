//FormAI DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>

int main() {
    int arr[] = {11, 22, 33, 44, 55, 66, 77};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    printf("Enter a number to search for: ");
    scanf("%d", &x);
    int found = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("%d was found at index %d\n", x, i);
    } else {
        printf("%d was not found in the array\n", x);
    }
    return 0;
}