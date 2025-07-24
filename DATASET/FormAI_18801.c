//FormAI DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Holmesian variables
    char file_name[50];
    char key[10];
    int ch, i;

    // Get file name and key from user
    printf("Enter name of file to encrypt: ");
    scanf("%s", file_name);
    printf("Enter encryption key (10 characters max): ");
    scanf("%s", key);

    // Open the input file and check for errors
    FILE *input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open file %s for reading.", file_name);
        exit(1);
    }

    // Create output file and check for errors
    FILE *output_file = fopen("encrypted", "wb+");
    if (output_file == NULL) {
        printf("Error: Could not create encrypted file for writing.");
        exit(1);
    }

    // Encrypt file using XOR operation
    i = 0;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ key[i], output_file);
        i++;
        if (i == 10) {
            i = 0;
        }
    }

    // Close both files and print success message
    fclose(input_file);
    fclose(output_file);
    printf("File %s has been encrypted successfully!\n", file_name);

    return 0;
}