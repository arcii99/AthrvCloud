//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define ARRAY_SIZE 5000

// Define the flower struct
typedef struct {
    char* name;
    int petals;
    float price;
} flower;

// Define the sorting function
void sort_flowers(flower* f, int n) {
    // Bubble sort
    flower tmp;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (f[j].price > f[j+1].price) {
                tmp = f[j];
                f[j] = f[j+1];
                f[j+1] = tmp;
            }
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the array of flowers
    flower bouquet[ARRAY_SIZE];

    // Fill the array with random flowers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        bouquet[i].name = "Flower";
        bouquet[i].petals = rand() % 50;
        bouquet[i].price = ((float)(rand() % 500)) / 100.0;
    }

    // Print a cheerful message
    printf("Welcome to the Flower Sorting Benchmark!\n");

    // Time the sorting function for the first array
    clock_t start_time = clock();
    sort_flowers(bouquet, ARRAY_SIZE);
    clock_t end_time = clock();

    // Calculate the time elapsed and print a message
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("It took %.3f seconds to sort the first array of flowers.\n", elapsed_time);

    // Fill the array with more random flowers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        bouquet[i].name = "Bloom";
        bouquet[i].petals = rand() % 30;
        bouquet[i].price = ((float)(rand() % 1000)) / 100.0;
    }

    // Print another cheerful message
    printf("Let's try sorting a different array of flowers!\n");

    // Time the sorting function for the second array
    start_time = clock();
    sort_flowers(bouquet, ARRAY_SIZE);
    end_time = clock();

    // Calculate the time elapsed and print a final message
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("It took only %.3f seconds to sort the second array!\n", elapsed_time);
    
    // Hooray! We're done.
    printf("Thanks for playing! Have a blooming great day!\n");

    return 0;
}