//FormAI DATASET v1.0 Category: File Encyptor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to the C File Encryptor!\n");
    printf("Please enter the filename to encrypt: ");

    char filename[100];
    scanf("%s", filename);

    FILE *input_file = fopen(filename, "rb");

    if(input_file == NULL)
    {
        printf("File not found!");
        return 0;
    }

    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    char* buffer = (char*)malloc(file_size);
    fread(buffer, file_size, 1, input_file);
    fclose(input_file);

    printf("Enter the encryption key: ");
    char encryption_key[100];
    scanf("%s", encryption_key);

    int key_sum = 0;
    for(int i = 0; i < strlen(encryption_key); i++)
    {
        key_sum += encryption_key[i];
    }

    int enc_sum = 0;
    for(int i = 0; i < file_size; i++)
    {
        buffer[i] = buffer[i] ^ key_sum;
        enc_sum += buffer[i];
    }

    char new_filename[100];
    strcpy(new_filename, filename);
    strcat(new_filename, "_encrypted");

    FILE *output_file = fopen(new_filename, "wb");
    fwrite(buffer, file_size, 1, output_file);
    fclose(output_file);

    printf("File successfully encrypted!\n");
    printf("Encrypted file saved as: %s\n", new_filename);
    printf("Encrypted file checksum: %d", enc_sum);

    free(buffer);

    return 0;
}