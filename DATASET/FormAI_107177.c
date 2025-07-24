//FormAI DATASET v1.0 Category: Data structures visualization ; Style: statistical
// C Data Structures Visualization Example Program

#include <stdio.h>
#include <stdlib.h>

// Define the Inverted Triangle Struct
typedef struct {
    int size;       // Size of the triangle
    char fillChar;  // Character to fill the triangle with
} InvertedTriangle;

// Define the Statistics Struct
typedef struct {
    int max;        // Maximum value in the dataset
    int min;        // Minimum value in the dataset
    float avg;      // Average value in the dataset
} Statistics;

// Function to create a new Inverted Triangle
InvertedTriangle* createInvertedTriangle(int size, char fillChar) {
    InvertedTriangle* triangle = malloc(sizeof(InvertedTriangle));
    triangle->size = size;
    triangle->fillChar = fillChar;

    return triangle;
}

// Function to print the Inverted Triangle
void printInvertedTriangle(InvertedTriangle* triangle) {
    int spacesBefore = triangle->size - 1;
    int stars = 1;

    for (int i = 0; i < triangle->size; i++) {
        for (int j = 0; j < spacesBefore; j++) {
            printf(" ");
        }

        for (int j = 0; j < stars; j++) {
            printf("%c", triangle->fillChar);
        }

        printf("\n");

        spacesBefore--;
        stars += 2;
    }
}

// Function to create a new Statistics Struct
Statistics* createStatistics(int* dataset, int size) {
    Statistics* stats = malloc(sizeof(Statistics));
    int sum = 0;
    int max = dataset[0];
    int min = dataset[0];

    for (int i = 0; i < size; i++) {
        sum += dataset[i];

        if (dataset[i] > max) {
            max = dataset[i];
        }

        if (dataset[i] < min) {
            min = dataset[i];
        }
    }

    stats->max = max;
    stats->min = min;
    stats->avg = (float) sum / size;

    return stats;
}

// Function to print the Statistics Struct
void printStatistics(Statistics* stats) {
    printf("Maximum value: %d\n", stats->max);
    printf("Minimum value: %d\n", stats->min);
    printf("Average value: %.2f\n", stats->avg);
}

int main() {
    // Create an Inverted Triangle and print it
    InvertedTriangle* triangle = createInvertedTriangle(5, '*');
    printf("Inverted Triangle:\n");
    printInvertedTriangle(triangle);
    printf("\n");

    // Create a dataset and calculate the statistics
    int dataset[5] = {5, 10, 15, 20, 25};
    Statistics* stats = createStatistics(dataset, 5);

    // Print the statistics
    printf("Statistics:\n");
    printStatistics(stats);
    printf("\n");

    // Free the memory
    free(triangle);
    free(stats);

    return 0;
}