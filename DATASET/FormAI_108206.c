//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    FILE *file_pointer;
    char filename[MAX_LENGTH];
    char data[MAX_LENGTH];
    
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open file for writing
    file_pointer = fopen(filename, "w");
    if (file_pointer == NULL) {
        printf("Error while opening file!");
        exit(1);
    }

    printf("\nEnter some text: ");
    scanf(" %[^\n]s", data);

    // Write data to the file
    fprintf(file_pointer, "%s", data);

    // Close the file
    fclose(file_pointer);

    // Open the same file for reading
    file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        printf("Error while opening file!");
        exit(1);
    }

    // Read data from the file and print it
    printf("\nThe file contains:\n");
    while (fgets(data, MAX_LENGTH, file_pointer)) {
        printf("%s", data);
    }

    // Close the file
    fclose(file_pointer);

    return 0;
}