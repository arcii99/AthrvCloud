//FormAI DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recoverData(char *source, char *destination) {

    // Open the source file for reading
    FILE *sourceFile = fopen(source, "r");
    if (sourceFile == NULL) {
        printf("Could not open the file '%s' for reading.\n", source);
        return;
    }

    // Open the destination file for writing
    FILE *destinationFile = fopen(destination, "w");
    if (destinationFile == NULL) {
        printf("Could not open the file '%s' for writing.\n", destination);
        fclose(sourceFile);
        return;
    }

    // Read the data from the source file and write it to the destination file
    int size;
    char data[100];
    while ((size = fread(data, 1, sizeof(data), sourceFile)) > 0) {
        fwrite(data, 1, size, destinationFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("Data successfully recovered from '%s' and saved to '%s'!\n", source, destination);
}

int main() {

    printf("Welcome to the Data Recovery Tool!\n");

    // Get the source file name
    char source[100];
    printf("Enter the name of the file to recover: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0;

    // Get the destination file name
    char destination[100];
    printf("Enter the name of the file to save the recovered data to: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0;

    // Recover the data and save it to the destination file
    recoverData(source, destination);

    return 0;
}