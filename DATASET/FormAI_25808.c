//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>

int main() {

    // Creating a file pointer to file
    FILE *file;

    // Opening a file for writing
    file = fopen("happy_file.txt", "w");

    // Checking if the file exists and can be opened
    if (file == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Writing to file
    fprintf(file, "Hello World! This is a happy file handling program!");

    // Closing the file
    fclose(file);

    // Opening the same file for reading
    file = fopen("happy_file.txt", "r");

    // Checking if the file exists and can be opened
    if (file == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Reading from file
    char c = fgetc(file);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(file);
    }

    // Closing the file
    fclose(file);

    return 0;
}