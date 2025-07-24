//FormAI DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>

int invasive_search(int arr[], int n, int x) {
    int i = 0;
    while (i < n) {
        if (arr[i] == x) {
            printf("I have found the element you were looking for! It's at index %d\n", i);
            return i;
        }
        i++;
    }
    printf("I'm sorry, but I couldn't find the element you were looking for.\n");
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 13, 21, 34, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;
    
    printf("I'm going to search for the number %d in this array: ", x);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    invasive_search(arr, n, x);
    
    return 0;
}