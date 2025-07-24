//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>

int main() {
    FILE *file_pointer;

    // Creating and opening a new file for writing
    file_pointer = fopen("example.txt", "w");

    // Writing data to the file
    fprintf(file_pointer, "This is an example file.\n");

    // Closing the file
    fclose(file_pointer);

    // Opening the file for reading
    file_pointer = fopen("example.txt", "r");

    // Reading data from the file
    char character;
    while ((character = fgetc(file_pointer)) != EOF) {
        printf("%c", character);
    }
    printf("\n");

    // Closing the file
    fclose(file_pointer);

    return 0;
}