//FormAI DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

void encrypt_file(char *in_file, char *out_file) {
    FILE *f1, *f2;
    char c;

    // Open input file
    f1 = fopen(in_file, "r");

    // Open output file
    f2 = fopen(out_file, "w");

    // Read input file and write encrypted data to output file
    while ((c = fgetc(f1)) != EOF) {
        c = c + 3;
        fputc(c, f2);
    }

    // Close files
    fclose(f1);
    fclose(f2);

    printf("File encrypted successfully!\n");
}

int main() {
    char input_file[100], output_file[100];

    // Get input file name
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", input_file);

    // Get output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Encrypt file
    encrypt_file(input_file, output_file);

    return 0;
}