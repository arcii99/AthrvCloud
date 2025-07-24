//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char filename[20];
    FILE *fp;

    // Ask the user for a filename to open
    printf("Enter a filename: ");
    scanf("%s", filename);

    // Attempt to open the file for reading
    fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        // If the file couldn't be opened, print an error message
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("File %s opened successfully!\n", filename);

    // Read the contents of the file
    char buffer[100];
    while (fgets(buffer, 100, fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);

    return 0;
}