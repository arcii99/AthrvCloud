//FormAI DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>

int main() {
    int array[5] = { 5, 3, 2, 4, 1 };
    int i, j, temp, pass = 0;
    
    printf("Unsorted Array: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    for(i = 0; i < 4; i++) {
        for(j = i + 1; j < 5; j++) {
             if (array[i] > array[j]) {
                 temp = array[i];
                 array[i] = array[j];
                 array[j] = temp;
             }
        }
        printf("Pass %d: ", pass + 1);
        for(j = 0; j < 5; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");
        pass++;
    }

    printf("Sorted Array: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}