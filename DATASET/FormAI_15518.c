//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>

int main() {
    int arr[10] = {1, 3, 7, 9, 12, 15, 17, 19, 22, 25};
    int n = sizeof(arr)/sizeof(int); //Calculating length of array
    int element;
    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    int low = 0, high = n - 1, middle;

    while(low <= high) {
        middle = (low + high) / 2;

        if(arr[middle] == element) {
            printf("Element found at index %d\n", middle);
            return 0;
        }
        else if(arr[middle] < element) {
            low = middle + 1;
        }
        else {
            high = middle - 1;
        }
    }
    printf("Element not found in array\n");
    return 0;
}