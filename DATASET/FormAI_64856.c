//FormAI DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The encryption key
#define KEY 0xA5

//Encodes the given string using the Caesar cipher algorithm
void encode(char* str, int key)
{
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        str[i] += key;
    }
}

//Decodes the given string using the Caesar cipher algorithm
void decode(char* str, int key)
{
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        str[i] -= key;
    }
}

//Encrypts the given file using the Modern Encryption algorithm and writes the encrypted data to output file
void encryptFile(char* inputFile, char* outputFile)
{
    FILE* input = fopen(inputFile, "rb");
    if(input == NULL)
    {
        printf("Error opening input file!\n");
        return;
    }

    FILE* output = fopen(outputFile, "wb");
    if(output == NULL)
    {
        fclose(input);
        printf("Error opening output file!\n");
        return;
    }

    //Get the file size
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    fseek(input, 0, SEEK_SET);

    //Allocate memory for the data
    char* data = malloc(size);
    if(data == NULL)
    {
        fclose(input);
        fclose(output);
        printf("Error: Out of memory!\n");
        return;
    }

    //Read the data from the file
    fread(data, 1, size, input);

    //Encrypt the data
    for(int i = 0; i < size; i++)
    {
        data[i] ^= KEY;
    }

    //Write the encrypted data to the output file
    fwrite(data, 1, size, output);

    //Cleanup
    free(data);
    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");
}

//Decrypts the given file using the Modern Encryption algorithm and writes the decrypted data to output file
void decryptFile(char* inputFile, char* outputFile)
{
    FILE* input = fopen(inputFile, "rb");
    if(input == NULL)
    {
        printf("Error opening input file!\n");
        return;
    }

    FILE* output = fopen(outputFile, "wb");
    if(output == NULL)
    {
        fclose(input);
        printf("Error opening output file!\n");
        return;
    }

    //Get the file size
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    fseek(input, 0, SEEK_SET);

    //Allocate memory for the data
    char* data = malloc(size);
    if(data == NULL)
    {
        fclose(input);
        fclose(output);
        printf("Error: Out of memory!\n");
        return;
    }

    //Read the data from the file
    fread(data, 1, size, input);

    //Decrypt the data
    for(int i = 0; i < size; i++)
    {
        data[i] ^= KEY;
    }

    //Write the decrypted data to the output file
    fwrite(data, 1, size, output);

    //Cleanup
    free(data);
    fclose(input);
    fclose(output);

    printf("File decrypted successfully!\n");
}

//The entry point of the program
int main()
{
    //Encrypt a file
    encryptFile("input.txt", "output.txt");

    //Decrypt the encrypted file
    decryptFile("output.txt", "decrypted.txt");

    return 0;
}