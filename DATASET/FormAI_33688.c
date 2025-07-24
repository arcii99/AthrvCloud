//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main() {

    // Create a file pointer and open the file for writing
    FILE *file = fopen("example.txt", "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    // Write some text to the file
    fprintf(file, "Hello, world!\n");
    fprintf(file, "This is a file handling program.\n");
    fprintf(file, "We are writing data to a file.\n");

    // Close the file
    fclose(file);

    // Open the same file for reading
    FILE *read_file = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (read_file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    // Read the contents of the file and print them to the console
    char text[100];
    while (fgets(text, 100, read_file) != NULL) {
        printf("%s", text);
    }

    // Close the file
    fclose(read_file);

    return 0;
}