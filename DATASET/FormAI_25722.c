//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

// Structure to store data
typedef struct Data {
    int id;
    char name[20];
    float value;
} Data;

// Sorting function
int compare(const void* a, const void* b) {
    return ((Data*)a)->id - ((Data*)b)->id;
}

int main() {
    // Allocate memory
    Data* arr = (Data*)malloc(SIZE * sizeof(Data));
    if (arr == NULL) {
        perror("Failed to allocate memory.");
        return 1;
    }

    // Initialize data
    for (int i = 0; i < SIZE; i++) {
        arr[i].id = SIZE - i;
        sprintf(arr[i].name, "Name_%d", i);
        arr[i].value = i * 0.5;
    }

    // Sort data
    qsort(arr, SIZE, sizeof(Data), compare);

    // Print results
    for (int i = 0; i < SIZE; i++) {
        printf("Id: %d, Name: %s, Value: %.2f\n", arr[i].id, arr[i].name, arr[i].value);
    }

    // Free memory
    free(arr);

    return 0;
}