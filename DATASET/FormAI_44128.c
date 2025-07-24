//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define MAX_STRING_SIZE 100

int main() {
    char* input[MAX_STRING_SIZE];
    int num_strings = 0;
    int i, j;
    printf("Enter the number of strings to be sorted: ");
    scanf("%d", &num_strings);

    // Dynamic Memory Allocation to fit input strings
    for (i = 0; i < num_strings; i++) {
        input[i] = (char*)malloc(MAX_STRING_SIZE * sizeof(char));
        printf("Enter the string %d: ", i+1);
        scanf("%s", input[i]);
    }

    // Using OpenMP for asynchronous sorting
    #pragma omp parallel for private(i, j)
    for (i = 0; i < num_strings; i++) {
        for (j = i+1; j < num_strings; j++) {
            if (strcmp(input[i], input[j]) > 0) {
                // swap the strings
                char* temp_str = input[i];
                input[i] = input[j];
                input[j] = temp_str;
            }
        }
    }

    // Displaying the sorted strings
    printf("\nSorted Strings:\n");
    for (i = 0; i < num_strings; i++) {
        printf("%s\n", input[i]);
    }

    // Freeing the memory allocated
    for (i = 0; i < num_strings; i++) {
        free(input[i]);
    }
    return 0;
}