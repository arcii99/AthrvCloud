//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int arr[1000000]; //a big array to make things interesting

    //populate array with random numbers
    for(int i=0; i<1000000; i++) {
        arr[i] = rand();
    }

    //perform bubble sort algorithm
    for(int i=0; i<1000000-1; i++) {
        for(int j=0; j<1000000-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                //swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Array sorted successfully! Here are the first 10 elements:\n");

    //print first 10 elements
    for(int i=0; i<10; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}