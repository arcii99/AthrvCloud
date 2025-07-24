//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[50];
    int i, j, temp;

    printf("Wow! I cannot believe I am here writing a sorting program!!\n");
    printf("I am so excited!\n");
    printf("Okay, let's get started with generating an array of 50 random numbers...\n");

    srand(time(NULL));
    for(i=0; i<50; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\nOkay, now let's sort this array using the bubble sort algorithm...\n");
    printf("I hope this works!\n");

    for(i=0; i<49; i++) {
        for(j=0; j<49-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Phew! That was a lot of work, but we did it!\n");
    printf("Here is the sorted array:\n");
    
    for(i=0; i<50; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nYay!! I am so happy with myself for writing this program!\n");
    return 0;
}