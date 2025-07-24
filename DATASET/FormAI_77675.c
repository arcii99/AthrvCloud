//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file_ptr;
    char text[1000];
    int length;

    // Ask user for file path
    printf("Enter the path of the text file: ");
    fgets(text, 1000, stdin);
    length = strlen(text);
    text[length-1] = '\0';

    // Attempt to open the file
    file_ptr = fopen(text, "a+");
    if (file_ptr == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    // Print a puzzle to the console
    printf("Crack this code to get the next clue:\n");
    printf("86 104 97 116 39 115 32 103 111 105 110 103 32 111 110 63\n");

    // Get user input to solve puzzle
    fgets(text, 1000, stdin);
    length = strlen(text);
    text[length-1] = '\0';

    // Check if the answer is correct
    if (strcmp(text, "What's going on?") != 0) {
        printf("Incorrect answer.\n");
        return 1;
    }

    // Write the next clue to the file
    fprintf(file_ptr, "The next clue is: 'The quick brown fox jumps over the lazy dog.'\n");

    // Close the file
    fclose(file_ptr);

    // Print success message
    printf("Congratulations! You solved the puzzle and found the next clue.\n");

    return 0;
}