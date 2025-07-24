//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>

// Function: xor_file
// Description: XORs (encrypts/decrypts) the contents of the file with the given key
// Parameters:
//      - filepath: path of the file to encrypt/decrypt
//      - key: key to use for encryption/decryption
void xor_file(char* filepath, char key) {
    // Open file in binary mode
    FILE *file = fopen(filepath, "rb+");

    if (file) {
        // Read the file byte by byte, XOR it with the key and write the result back
        int c = fgetc(file);
        while (c != EOF) {
            fseek(file, -1, SEEK_CUR); // Move file pointer back one byte
            fputc(c ^ key, file); // XOR the byte with the key and write back to the file
            c = fgetc(file); // Read next byte
        }

        // Close the file
        fclose(file);
    } else {
        printf("Error: Could not open file %s\n", filepath);
    }
}

int main() {
    char filepath[100];
    char key;

    // Prompt user for file path and key
    printf("Enter file path: ");
    scanf("%s", filepath);
    printf("Enter key: ");
    scanf(" %c", &key);

    // Encrypt/decrypt the file using XOR
    xor_file(filepath, key);

    printf("Done\n");

    return 0;
}