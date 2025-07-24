//FormAI DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to simulate data recovery
bool recover_data(char* filename) {
    printf("Recovering data from %s...\n", filename);
    // Simulating data recovery process
    // Code for data recovery goes here
    return true;
}

// Function to check if file exists
bool file_exists(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

// Function to prompt user to enter file name
char* get_filename() {
    printf("Enter file name: ");
    char* filename = (char*) malloc(100 * sizeof(char));
    scanf("%s", filename);
    return filename;
}

// Main function
int main() {
    printf("\n*** Data Recovery Tool ***\n\n");
    char* filename = get_filename();
    if (file_exists(filename)) {
        if (recover_data(filename)) {
            printf("\nData recovered successfully!\n");
        } else {
            printf("\nData recovery failed!\n");
        }
    } else {
        printf("\nThe file %s does not exist.\n", filename);
    }
    free(filename);
    return 0;
}