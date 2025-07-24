//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>

#define MAX_SIZE 101

int main() {
    // Create a file pointer to read file
    FILE *file;

    // Open the file in read mode
    file = fopen("example.txt", "r");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }

    // Read the contents of the file and display it
    char str[MAX_SIZE];
    while (fgets(str, MAX_SIZE, file)) {
        printf("%s", str);
    }

    // Close the file
    fclose(file);

    // Create a file pointer to write file
    FILE *writeFile;

    // Open the file in write mode
    writeFile = fopen("example.txt", "w");

    // Check if file is opened successfully
    if (writeFile == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }

    // Get input from user and write it to the file
    char input[MAX_SIZE];
    printf("Enter text to write to file:\n");
    fgets(input, MAX_SIZE, stdin);
    fprintf(writeFile, "%s", input);

    // Close the file
    fclose(writeFile);

    return 0;
}