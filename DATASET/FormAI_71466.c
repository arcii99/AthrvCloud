//FormAI DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the immersive file handling program!\n\n");

    // Creating a new file
    FILE *fp;
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error: Failed to create file\n");
        exit(1);
    }

    printf("A new file named \"example.txt\" has been created.\n\n");

    // Writing to the file
    fprintf(fp, "This is an example line.\n");
    fprintf(fp, "This is another example line.\n");

    printf("Two lines have been written to the new file.\n\n");

    // Closing the file
    fclose(fp);
    printf("The file has been closed succesfully.\n\n");

    // Opening an existing file for reading
    printf("Now, let's read the content of the file.\n");

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open file for reading\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    printf("\nThe content of the file has been read and shown on the screen.\n\n");

    // Closing the file
    fclose(fp);
    printf("The file has been closed succesfully.\n\n");

    printf("Thank you for using the immersive file handling program!\n");

    return 0;
}