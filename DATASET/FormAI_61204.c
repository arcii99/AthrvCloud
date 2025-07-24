//FormAI DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main(void) {
    // Ask user for file name
    char file_name[MAX_LENGTH];
    printf("Enter the file name: ");
    fgets(file_name, MAX_LENGTH, stdin);
    file_name[strcspn(file_name, "\n")] = 0; // remove newline character

    // Attempt to open file
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Get size of file
    fseek(fp, 0L, SEEK_END);
    long int file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for file contents
    char *file_contents = (char*) malloc(file_size);
    if (file_contents == NULL) {
        printf("Error: Unable to allocate memory.\n");
        fclose(fp);
        return 1;
    }

    // Read file contents into memory
    size_t result = fread(file_contents, 1, file_size, fp);
    if (result != file_size) {
        printf("Error: Unable to read file into memory.\n");
        free(file_contents);
        fclose(fp);
        return 1;
    }

    // Attempt to recover file
    printf("Attempting to recover data...\n");
    int num_corrupted_bytes = 0;
    for (int i = 0; i < file_size; i++) {
        if (file_contents[i] > 122 || file_contents[i] < 32) {
            file_contents[i] = ' ';
            num_corrupted_bytes++;
        }
    }

    // Save recovered file
    char new_file_name[MAX_LENGTH];
    printf("Enter the name of the new file: ");
    fgets(new_file_name, MAX_LENGTH, stdin);
    new_file_name[strcspn(new_file_name, "\n")] = 0; // remove newline character
    FILE *new_fp = fopen(new_file_name, "wb");
    if (new_fp == NULL) {
        printf("Error: Unable to create new file.\n");
        free(file_contents);
        fclose(fp);
        return 1;
    }
    fwrite(file_contents, 1, file_size, new_fp);
    fclose(new_fp);

    // Print results
    printf("Data recovery complete with %d corrupted bytes corrected.\n", num_corrupted_bytes);

    // Free memory and close files
    free(file_contents);
    fclose(fp);

    return 0;
}