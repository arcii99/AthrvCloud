//FormAI DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50];
    char data[100];

    // Get file name from user
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file exists
    if (fp == NULL) {
        printf("File does not exist.\n");
        exit(0);
    }

    // Read data from file
    fgets(data, 100, fp);

    // Print the data
    printf("Data in %s: %s", filename, data);

    // Close the file
    fclose(fp);
    
    return 0;
}