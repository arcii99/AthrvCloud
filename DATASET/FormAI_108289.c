//FormAI DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Welcome Message
void welcome() {
    printf("Welcome to Happy Data Recovery Tool!\n");
    printf("This tool will help you recover your lost data in a happy way!\n");
    printf("Let's get started!\n");
}

// Function to read and recover data
void readAndRecoverData() {
    FILE *fp;
    char filename[100];
    char buffer[1024];
    int numRead;

    // Ask user for filename input
    printf("\nEnter the filename to recover data: ");
    scanf("%s", filename);

    // Open the file in read mode
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("\nOops! %s file could not be opened. Please check if the file exists and try again.\n", filename);
        return;
    }

    // Read data from file and display it
    printf("\nRecovered Data:\n");
    while ((numRead = fread(buffer, sizeof(char), 1024, fp)) > 0) {
        fwrite(buffer, sizeof(char), numRead, stdout);
    }

    // Close the file
    fclose(fp);

    printf("\nYour data has been successfully recovered in a happy way!\n");
}

// Main function
int main() {
    welcome();
    readAndRecoverData();
    return 0;
}