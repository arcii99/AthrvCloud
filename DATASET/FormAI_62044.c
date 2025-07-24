//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void display_help() {
    printf("Usage: ./datarecovery <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {

    // Check if the correct number of arguments were given
    if (argc != 3) {
        printf("Invalid arguments.\n");
        display_help();
        return 1;
    }

    // Open the input file and check if it exists
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Failed to open input file.\n");
        display_help();
        return 1;
    }

    // Determine the size of the file
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory for the file
    char *file_data = (char *) malloc(file_size);
    if (!file_data) {
        printf("Failed to allocate memory.\n");
        fclose(input_file);
        return 1;
    }

    // Read the file contents into memory
    size_t read_size = fread(file_data, 1, file_size, input_file);
    if (read_size != file_size) {
        printf("Failed to read entire file.\n");
        fclose(input_file);
        free(file_data);
        return 1;
    }

    // Close the input file
    fclose(input_file);

    // Open the output file and check if it exists
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Failed to open output file.\n");
        display_help();
        free(file_data);
        return 1;
    }

    // Write the file contents to the output file
    size_t write_size = fwrite(file_data, 1, file_size, output_file);
    if (write_size != file_size) {
        printf("Failed to write entire file.\n");
        fclose(output_file);
        free(file_data);
        return 1;
    }

    // Close the output file
    fclose(output_file);

    // Free the memory allocated for the file data
    free(file_data);

    // Indicate success
    printf("File recovery complete.\n");
    return 0;
}