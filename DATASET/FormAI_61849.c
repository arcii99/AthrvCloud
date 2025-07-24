//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the C File Encryptor!\n");
    printf("Enter the name of the file you want to encrypt: ");
    char file_name[100];
    scanf("%s", file_name);
    FILE *input_file = fopen(file_name, "r");
    
    if (input_file == NULL) {
        printf("File not found.\n");
        return 1;
    }
    
    char output_file_name[100];
    strcpy(output_file_name, file_name);
    strcat(output_file_name, ".encrypted");
    FILE *output_file = fopen(output_file_name, "w");
    
    char encryption_key[10];
    printf("Enter the encryption key (must be 10 characters long): ");
    scanf("%s", encryption_key);
    
    if (strlen(encryption_key) != 10) {
        printf("Key must be 10 characters long.\n");
        return 1;
    }
    
    printf("Encrypting file...\n");
    char c;
    int i = 0;
    
    while ((c = fgetc(input_file)) != EOF) {
        fputc(c ^ encryption_key[i], output_file);
        i++;
        if (i == 10) {
            i = 0;
        }
    }
    
    printf("Encryption successful!\n");
    fclose(input_file);
    fclose(output_file);
    return 0;
}