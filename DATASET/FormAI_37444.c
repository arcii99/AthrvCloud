//FormAI DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to C Data Recovery Tool!\n");

    // Ask user for file name
    printf("Please enter the file name: ");
    char file_name[100];
    scanf("%s", file_name);

    // Open file in read mode
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        // File not found error message
        printf("Error: File not found.\n");
        return 1;
    }

    // Read file contents into buffer
    char buffer[1024];
    int file_size = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        file_size += sizeof(buffer);
    }

    // Close file
    fclose(file);

    // Create output file
    char output_file_name[100];
    sprintf(output_file_name, "recovered_%s", file_name);
    FILE *output_file = fopen(output_file_name, "w");

    // Write buffer to output file in reverse
    for (int i = file_size - 1; i >= 0; i--) {
        fputc(buffer[i], output_file);
    }

    // Close output file
    fclose(output_file);

    // Success message
    printf("File %s successfully recovered as %s.\n", file_name, output_file_name);

    return 0;
}