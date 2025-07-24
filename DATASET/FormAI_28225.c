//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, search, array[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    srand(time(NULL));
    for(i=0; i<n; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\nEnter the element you want to search for: ");
    scanf("%d", &search);
    for(i=0; i<n; i++) {
        if(array[i] == search) {
            printf("%d is present at index %d in the array.\n", search, i);
            break;
        }
    }
    if(i==n) {
        printf("%d is not present in the array.\n", search);
    }
    return 0;
}