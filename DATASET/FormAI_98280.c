//FormAI DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int value;
    bool sorted;
} Element;

Element array[SIZE];

bool areAllElementsSorted() {
    for (int i = 0; i < SIZE; i++) {
        if (!array[i].sorted) {
            return false;
        }
    }
    return true;
}

void displayArray() {
    printf("[");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", array[i].value);
        if (i != SIZE-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int compare(const void *a, const void *b) {
    return (*(Element*)a).value - (*(Element*)b).value;
}

void sort() {
    qsort(array, SIZE, sizeof(Element), compare);
    for (int i = 0; i < SIZE; i++) {
        array[i].sorted = true;
    }
}

void mix() {
    for (int i = 0; i < SIZE; i++) {
        array[i].sorted = false;
    }
}

int main() {
    srand(time(NULL));
    //initialize array
    for (int i = 0; i < SIZE; i++) {
        array[i].value = rand() % 100;
        array[i].sorted = false;
    }
    printf("Before sorting:\n");
    displayArray();
    while (!areAllElementsSorted()) {
        mix();
        sort();
    }
    printf("After sorting:\n");
    displayArray();
    return 0;
}