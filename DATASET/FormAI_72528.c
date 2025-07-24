//FormAI DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>

int main() {

    // Open the file in write mode
    FILE *file = fopen("example.txt", "w");

    // Check if file has been opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write some text to the file
    fprintf(file, "This is an example file.\n");
    fprintf(file, "It contains some random text.\n");

    // Close the file
    fclose(file);

    // Open the file in read mode
    file = fopen("example.txt", "r");

    // Check if file has been opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the file contents and display them to the console
    int c;
    printf("File contents:\n");
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Close the file
    fclose(file);

    // Delete the file
    int status = remove("example.txt");
    if (status == 0) {
        printf("\nFile deleted successfully.\n");
    } else {
        printf("\nError deleting file.\n");
    }

    return 0;
}