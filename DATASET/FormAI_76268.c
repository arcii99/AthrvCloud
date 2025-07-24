//FormAI DATASET v1.0 Category: File Encyptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Let's create a unique C File Encryptor program!\n");
    printf("Enter the filename you want to encrypt: ");
    char filename[50];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file.\n");
        return 0;
    }

    // Get file size
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Create encrypted file
    char new_filename[50];
    strcpy(new_filename, filename);
    strcat(new_filename, ".enc");
    FILE *new_file = fopen(new_filename, "w");

    // Generate random key
    int key = rand() % 255;

    // Write key to file
    fprintf(new_file, "%d\n", key);

    // Encrypt file using key
    for(int i=0; i<size; i++){
        char c = fgetc(file);
        c ^= key;
        fputc(c, new_file);
    }

    fclose(file);
    fclose(new_file);
    printf("Successfully encrypted file with key %d!\n", key);
    return 0;
}