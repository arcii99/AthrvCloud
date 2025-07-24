//FormAI DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char fileName[100], key[100], ch;
    
    printf("Enter file name (with extension): ");
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r+");
    
    if (fp == NULL){
        printf("Error: File not found.\n");
        exit(1);
    }
    
    printf("Enter a key to encrypt the file: ");
    scanf("%s", key);
    
    int keyLength = strlen(key);
    int i = 0;
    while(fscanf(fp, "%c", &ch) != EOF){ // Iterate through the file character by character
        ch = ch ^ key[i % keyLength]; // Apply xor operation with a character from key
        fseek(fp, -1, SEEK_CUR); // Move file pointer one step back
        fprintf(fp, "%c", ch); // Write back the encrypted character
        i++; // Move to next character from key
    }
    
    printf("\n%s file has been successfully encrypted with key: %s\n", fileName, key);
    fclose(fp);
    return 0;
}