//FormAI DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to shift characters by a certain key
char shiftChar(char c, int key){
    if(c >= 'A' && c <= 'Z'){
        return (char)(((c - 'A' + key) % 26) + 'A'); // shift upper case letters
    }else if(c >= 'a' && c <= 'z'){
        return (char)(((c - 'a' + key) % 26) + 'a'); // shift lower case letters
    }
    return c; // return other characters
}

int main(){
    char filename[100];
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);

    FILE *fInput, *fOutput;
    int key;
    printf("Enter a key value (between 1 and 25): ");
    scanf("%d", &key);

    char outputFilename[100];
    sprintf(outputFilename, "encrypted_%s", filename);

    fInput = fopen(filename, "r");
    fOutput = fopen(outputFilename, "w");

    if(fInput == NULL || fOutput == NULL){
        printf("Error opening files");
        exit(1);
    }

    char c;
    while((c = fgetc(fInput)) != EOF){
        char shiftedChar = shiftChar(c, key);
        fputc(shiftedChar, fOutput);
    }

    fclose(fInput);
    fclose(fOutput);

    printf("Encrypted successfully. Encrypted file: %s", outputFilename);

    return 0;
}