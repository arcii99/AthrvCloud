//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 0;
    printf("Please enter a number: ");
    if (scanf("%d", &num) == 0) {
        fprintf(stderr, "Error: Invalid input! Please enter an integer.\n");
        exit(EXIT_FAILURE);
    }
    if (num < 0 || num > 100) {
        fprintf(stderr, "Error: Invalid input! Please enter a number between 0 and 100.\n");
        exit(EXIT_FAILURE);
    }

    int arr[5] = {10, 20, 30, 40, 50};
    int idx = -1;
    printf("\nPlease enter an index: ");
    if (scanf("%d", &idx) == 0) {
        fprintf(stderr, "Error: Invalid input! Please enter an integer.\n");
        exit(EXIT_FAILURE);
    }
    if (idx < 0 || idx > 4) {
        fprintf(stderr, "Error: Invalid input! Please enter an index between 0 and 4.\n");
        exit(EXIT_FAILURE);
    }
    int val = arr[idx];
    printf("\nThe value at index %d is %d.\n", idx, val);

    FILE *fp;
    char filename[20];
    printf("\nPlease enter a filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("\nFile %s opened successfully!\n", filename);

    fclose(fp);

    printf("\nProgram completed successfully.\n");
    return 0;
}