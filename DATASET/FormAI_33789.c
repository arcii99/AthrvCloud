//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[20], text[50];

    // Getting the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Opening the file in write mode
    fp = fopen(filename, "w");

    // Checking if the file exists and can be opened in write mode
    if (fp == NULL) {
        printf("Error opening the file!");
        exit(1);
    }

    // Getting the text to be written to the file from the user
    printf("Enter the text to be written to the file: ");
    scanf(" %[^\n]s", text);

    // Writing the text to the file
    fprintf(fp, "%s", text);

    // Closing the file
    fclose(fp);

    // Opening the file in read mode
    fp = fopen(filename, "r");

    // Checking if the file exists and can be opened in read mode
    if (fp == NULL) {
        printf("Error opening the file!");
        exit(1);
    }

    // Reading the text from the file and displaying it to the user
    fgets(text, sizeof(text), fp);
    printf("The text in the file is: %s\n", text);

    // Closing the file
    fclose(fp);

    return 0;
}