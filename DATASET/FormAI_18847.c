//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is not a traditional clustering algorithm, but it's unique and fun!
// It will cluster random numbers into two groups based on odd vs even.

int main() {
    srand(time(0)); // initialize random seed 

    int even[50]; // array to store even numbers
    int odd[50]; // array to store odd numbers
    int even_count = 0; // number of even numbers
    int odd_count = 0; // number of odd numbers

    // randomly generate 100 numbers and classify them as even or odd
    for (int i = 0; i < 100; i++) {
        int num = rand() % 100 + 1; // generate random number between 1 and 100
        if (num % 2 == 0) { // check if even
            even[even_count] = num; // add to even array
            even_count++;
        } else { // odd
            odd[odd_count] = num; // add to odd array
            odd_count++;
        }
    }

    // print the clusters
    printf("Even cluster: ");
    for (int i = 0; i < even_count; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
    printf("Odd cluster: ");
    for (int i = 0; i < odd_count; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}