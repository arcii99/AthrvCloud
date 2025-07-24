//FormAI DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>

/* Function declaration */
void read_file(const char* file_path);

int main(int argc, char* argv[]) {
    /* Check if file path is provided as command line argument */
    if (argc < 2) {
        printf("Please provide file path as command line argument\n");
        exit(EXIT_FAILURE);
    }

    /* Read the file */
    read_file(argv[1]);

    return 0;
}

/* Function to read file and handle errors */
void read_file(const char* file_path) {
    /* Open the file */
    FILE* file_ptr = fopen(file_path, "r");

    /* Handle error if file cannot be opened */
    if (file_ptr == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    /* Read contents of the file */
    int c;
    while ((c = fgetc(file_ptr)) != EOF) {
        putchar(c);
    }

    /* Close the file */
    if (fclose(file_ptr) != 0) {
        printf("Error closing file!\n");
        exit(EXIT_FAILURE);
    }
}