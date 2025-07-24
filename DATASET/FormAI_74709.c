//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declare char array for file name
    char file_name[100];

    // Get file name from user input
    printf("Welcome to the post-apocalyptic file handler. Please enter the name of the file you want to access: ");
    scanf("%s", file_name);

    // Open file for reading and writing
    FILE *file_ptr = fopen(file_name, "r+");

    if (file_ptr == NULL) {
        // File failed to open
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Successfully opened file
    printf("File \"%s\" opened successfully.\n", file_name);

    // Read contents of file and print to console
    printf("Current contents of the file:\n");
    char file_contents[500];
    while (fgets(file_contents, 500, file_ptr) != NULL) {
        printf("%s", file_contents);
    }

    // Allow user to write to file
    printf("\nPlease enter the text you want to write to the file: ");
    char user_input[500];
    fgets(user_input, 500, stdin);

    // Write user input to file
    fprintf(file_ptr, "%s", user_input);

    // Close file
    fclose(file_ptr);

    printf("\nFile \"%s\" has been updated with your input.\n", file_name);

    return 0;
}