//FormAI DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define MAX 100

void main() {
    int i, j, temp;
    int arr[ARRAY_SIZE];
    srand(time(0)); // Seed the random function with the current time

    // Fill the array with random numbers between 0 and MAX
    for(i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % (MAX+1);
    }

    // Perform bubble sort on the array
    for(i=0; i<ARRAY_SIZE-1; i++) {
        for(j=0; j<ARRAY_SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the top 10 most frequent numbers in the array
    int freq[MAX+1] = {0};
    for(i=0; i<ARRAY_SIZE; i++) {
        freq[arr[i]]++;
    }

    printf("Top 10 most frequent numbers in the array:\n");
    for(i=0; i<10; i++) {
        int max = 0, max_idx;
        for(j=0; j<=MAX; j++) {
            if(freq[j] > max) {
                max = freq[j];
                max_idx = j;
            }
        }
        printf("%d. %d occurs %d times\n", i+1, max_idx, max);
        freq[max_idx] = 0;
    }
}