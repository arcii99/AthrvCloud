//FormAI DATASET v1.0 Category: File Encyptor ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defining the encryption key
#define KEY 0x2

// Function to encrypt the file
void encryptFile(char *fileName) {
    FILE *fptr;
    char ch;
    
    // Opening the file in read mode
    fptr = fopen(fileName, "rb+");
    if (fptr == NULL) {
        printf("Unable to open the file.\n");
        exit(1);
    }
    
    // Encrypting the content of the file
    while ((ch = fgetc(fptr)) != EOF) {
        ch = ch ^ KEY;
        fseek(fptr, -1, SEEK_CUR);
        fputc(ch, fptr);
    }
    
    // Closing the file
    fclose(fptr);
}

int main() {
    char fileName[100];
    
    // Taking the file name as input from the user
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", fileName);
    
    // Encrypting the file
    encryptFile(fileName);
    
    printf("File encrypted successfully.\n");
    
    return 0;
}