//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>

int main() {
    FILE *file;
    char text[100];

    // Open the file
    file = fopen("happy_text.txt", "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Oops! Something went wrong while opening the file.\n");
        return 1;
    }

    // Prompt the user to enter some happy lines
    printf("Yay! Let's write some happy lines\n");
    printf("Enter a line and press Enter. Type 'quit' to finish.\n");

    while (1) {
        fgets(text, sizeof(text), stdin);

        // Check if the user typed 'quit'
        if (strcmp(text, "quit\n") == 0) {
            break;
        }

        // Write the line to the file
        fputs(text, file);
    }

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("happy_text.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Oops! Something went wrong while opening the file.\n");
        return 1;
    }

    // Read and display the lines in the file
    printf("\n\nThese are the happy lines you have written:\n");

    while (fgets(text, sizeof(text), file) != NULL) {
        printf("%s", text);
    }

    // Close the file
    fclose(file);

    // Celebrate!
    printf("\n\nYay! You have successfully written happy lines to a file and read them back.\n");

    return 0;
}