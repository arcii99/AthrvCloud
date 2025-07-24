//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr; // Declare a file pointer
    char file_name[100]; // Declare a char array to store the filename
    printf("Woohoo, let's work with files!\n");
    printf("Enter the name of the file you want to create: ");
    scanf("%s", file_name); // Get the filename from user

    // Open the file in write mode
    file_ptr = fopen(file_name, "w");

    if (file_ptr == NULL) { // If file open fails
        printf("Uh oh, the file couldn't be created. Better luck next time!\n");
        exit(1);
    }

    printf("File created successfully, now let's start writing!\n");
    fprintf(file_ptr, "Writing to files in C is so much fun!\n");
    fprintf(file_ptr, "We can write anything we want, even code snippets like this one!\n");
    fprintf(file_ptr, "And we can do it all without leaving our favorite text editor!\n");

    printf("Alright, enough writing. Let's close the file and take a look at what we've done!\n");

    fclose(file_ptr); // Close the file

    // Open the file in read mode
    file_ptr = fopen(file_name, "r");

    if (file_ptr == NULL) { // If file open fails
        printf("Oh no, looks like we can't read the file now. Let's try again!\n");
        exit(1); 
    }

    char c; // Declare a char variable to read the file
    printf("Reading file: %s\n", file_name);
    while ((c = getc(file_ptr)) != EOF) { // Read the file character by character
        putchar(c); // Print each character to screen
    }

    fclose(file_ptr); // Close the file

    printf("Ha, that was awesome! Let's do it again sometime. Bye for now!\n");

    return 0;
}