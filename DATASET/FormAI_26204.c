//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>

int main() {
    // Create a file pointer
    FILE *fp;

    // Open the file for writing
    fp = fopen("example_file.txt", "w");

    // Check if the file opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Write data to the file
    fprintf(fp, "This is an example sentence.\n");

    // Close the file
    fclose(fp);

    // Open the file again for reading
    fp = fopen("example_file.txt", "r");

    // Check if the file opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read from the file
    char buffer[100];
    fgets(buffer, 100, fp);
    printf("Contents of file: %s", buffer);

    // Close the file
    fclose(fp);

    return 0;
}