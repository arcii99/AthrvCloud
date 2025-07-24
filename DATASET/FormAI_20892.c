//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;
    char fileName[50];
    char buffer[256];

    // Prompt user to enter file name
    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);

    // Open the file for reading
    fp = fopen(fileName, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: File does not exist.\n");
        exit(EXIT_FAILURE); // Exit program with error code
    }

    // Read and print file contents
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);

    return 0;
}