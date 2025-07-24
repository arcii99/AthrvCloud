//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int divide_numbers(int a, int b) {
    if (b == 0) {
        // Null Division Error
        printf("ERROR: Cannot divide by zero!\n");
        return -1;
    }
    return a/b;
}

int main() {
    int a = 100, b = 0;
    int result = divide_numbers(a, b);
    if (result == -1) {
        // Error handling for null division
        printf("Program exiting due to an error.\n");
        exit(1);
    }
    else {
        printf("%d/%d = %d\n", a, b, result);
    }
    
    int *arr = malloc(sizeof(int)*5);
    if (arr == NULL) {
        // Memory allocation error
        printf("ERROR: Failed to allocate memory!\n");
        exit(1);
    }
    else {
        printf("Memory allocation successful!\n");
        free(arr);
    }
    
    FILE *fp;
    fp = fopen("nonexistent_file.txt", "r");
    if (fp == NULL) {
        // File opening error
        printf("ERROR: Failed to open file!\n");
        exit(1);
    }
    else {
        printf("File opened successfully!\n");
        fclose(fp);
    }
    
    return 0;
}