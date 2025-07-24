//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Hello there! Today we're going to learn about file handling in C.\n");

    // File handling example
    FILE *fptr;
    char filename[50];
    printf("Please enter the name of the file you would like to create: ");
    scanf("%s", filename);
    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Oops, an error occurred while creating the file. Please try again later.\n");
        exit(1);
    }

    printf("Enter the text you would like to write to the file: ");
    char text[100];
    scanf(" %[^\n]s", text);

    fprintf(fptr, "%s", text);

    fclose(fptr);

    printf("File created successfully!\n");

    // File reading example
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Oops, an error occurred while reading the file. Please try again later.\n");
        exit(1);
    }

    char buffer[100];
    fgets(buffer, 100, fptr);
    printf("The text in the file is:\n%s\n", buffer);

    fclose(fptr);

    // Goodbye message
    printf("Thank you for learning about file handling with me! Have a great day!\n");

    return 0;
}