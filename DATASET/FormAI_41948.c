//FormAI DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char key[10] = "romantic";
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    fseek(fp, 0L, SEEK_END); // move cursor to end of file
    int size = ftell(fp); // get the file size
    fseek(fp, 0L, SEEK_SET); // move cursor back to beginning of file
    char *buffer = malloc(size); // allocate memory for file content

    fread(buffer, size, 1, fp); // read file content into buffer
    fclose(fp); // close file

    for (int i = 0; i < size; i++) {
        buffer[i] ^= key[i % strlen(key)]; // XOR encryption with key
    }

    char encrypted_filename[50];
    strcpy(encrypted_filename, filename);
    strcat(encrypted_filename, ".enc");
    fp = fopen(encrypted_filename, "w"); // create encrypted file
    fwrite(buffer, size, 1, fp); // write encrypted content to file
    fclose(fp); // close file

    free(buffer); // free allocated memory
    printf("File encrypted successfully and saved as %s!\n", encrypted_filename);
    return 0;
}