//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int encrypt_file(char *input_file_path, char *output_file_path, char *key) {

    // Open the input file
    FILE *input_file = fopen(input_file_path, "r");
    if (input_file == NULL) {
        printf("Error: Unable to open file '%s'", input_file_path);
        return 1;   // Return with error
    }

    // Open the output file
    FILE *output_file = fopen(output_file_path, "w");
    if (input_file == NULL) {
        printf("Error: Unable to create file '%s'", output_file_path);
        fclose(input_file);
        return 1;   // Return with error
    }

    // Read the key length
    int key_length = strlen(key);

    // Encryption buffer
    char buffer[MAX_SIZE];

    // Iterate through the input file and encrypt each character
    int i = 0;
    char c;
    while ((c = getc(input_file)) != EOF) {
        buffer[i++] = ((c ^ key[i % key_length]) + i) % 256;
        if (i == MAX_SIZE) {
            fwrite(buffer, sizeof(char), MAX_SIZE, output_file);
            i = 0;
        }
    }

    // Write the remaining characters to the output file
    if (i) {
        fwrite(buffer, sizeof(char), i, output_file);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;   // Return without error
}

int main() {

    char *input_file_path = "input.txt";
    char *output_file_path = "output.txt";
    char *key = "mysecretkey";

    int result = encrypt_file(input_file_path, output_file_path, key);
    if (result == 0) {
        printf("File encryption successful!\n");
    } else {
        printf("File encryption failed!\n");
    }

    return 0;
}