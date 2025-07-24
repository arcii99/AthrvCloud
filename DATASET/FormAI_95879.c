//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>

int main() {
    FILE *file_pointer;
    char user_input[100];

    // Opening file in write mode
    file_pointer = fopen("example.txt", "w");

    if (file_pointer == NULL) {
        printf("Error: File cannot be opened.\n");
        return 1; // Exit the program with error code
    }

    printf("Enter text to write in the file: ");
    fgets(user_input, 100, stdin);

    // Writing user's input into the file
    fputs(user_input, file_pointer);

    // Closing the file
    fclose(file_pointer);

    // Opening the file in read mode
    file_pointer = fopen("example.txt", "r");

    if (file_pointer == NULL) {
        printf("Error: File cannot be opened.\n");
        return 1; // Exit the program with error code
    }

    // Reading file and printing its content
    printf("Contents of the file: \n");
    char character;
    while ((character = fgetc(file_pointer)) != EOF) {
        printf("%c", character);
    }

    // Closing the file
    fclose(file_pointer);

    return 0; // Exit the program with success code
}