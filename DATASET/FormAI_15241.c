//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include<stdio.h>

int main(){
    printf("Welcome to the curious sorting program!\n");

    int array[10] = {3, 9, 1, 16, 5, 12, 8, 2, 4, 10};
    int i, j, temp;

    printf("Unsorted Array: ");
    for(i=0; i<10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Starting the sorting process...\n");

    // curious sorting algorithm
    for(i=0; i<10; i++){
        for(j=i+1; j<10; j++){
            if(array[j] < array[i]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                printf("Curious swap performed! Array elements switched are %d and %d\n", array[i], array[j]);
            }
        }
    }

    printf("Sorting complete!\n");

    printf("Sorted Array: ");
    for(i=0; i<10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}