//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[20], data[50];
    
    // Ask the user for the filename to be used
    printf("Enter the name of the file you want to create: ");
    scanf("%s", filename);

    // Open the file for writing
    fp = fopen(filename, "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Get data from the user and write it to the file
    printf("Enter data to be written to the file: ");
    scanf("%s", data);
    fprintf(fp, "%s", data);

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read data from the file and display it
    printf("The contents of the file are:\n");
    fseek(fp, 0, SEEK_SET);
    while (fgets(data, 50, fp) != NULL) {
        printf("%s", data);
    }

    // Close the file
    fclose(fp);

    return 0;
}