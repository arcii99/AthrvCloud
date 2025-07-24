//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the file in write mode
    FILE *fp;
    fp = fopen("example.txt", "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: File cannot be opened for writing\n");
        exit(0);
    }

    // Get user input and write to the file
    char input[100];
    printf("Enter text to write to the file: ");
    fgets(input, 100, stdin);
    fprintf(fp, "%s", input);

    // Close the file
    fclose(fp);

    // Open the file in read mode
    fp = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: File cannot be opened for reading\n");
        exit(0);
    }

    // Read the contents of the file and print to console
    char output[100];
    printf("Contents of the file: ");
    while (fgets(output, 100, fp)) {
        printf("%s", output);
    }

    // Close the file
    fclose(fp);

    return 0;
}