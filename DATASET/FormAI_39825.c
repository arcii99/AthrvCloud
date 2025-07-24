//FormAI DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include<stdio.h>
#include<string.h>

// Function to perform XOR encryption with a key
void encrypt(char* key, char* input, char* output)
{
    int len = strlen(input);
    int keyLen = strlen(key);
 
    for(int i = 0; i < len; i++)
    {
        output[i] = input[i] ^ key[i % keyLen];
    }
}

// Function to get input from the user
void getInput(char* input)
{
    printf("Enter the input: ");
    scanf("%s", input);
}

// Function to get key from the user
void getKey(char* key)
{
    printf("Enter the key: ");
    scanf("%s", key);
}

// Function to print the encrypted output
void printOutput(char* output)
{
    printf("Encrypted output: %s\n", output);
}

int main()
{
    char input[100];
    char key[100];
    char output[100];
    getInput(input);
    getKey(key);
    encrypt(key, input, output);
    printOutput(output);
    return 0;
}