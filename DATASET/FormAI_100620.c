//FormAI DATASET v1.0 Category: File Encyptor ; Style: curious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define KEY 10 // Key used to encrypt file content

void encryptFileContent(FILE*, FILE*);

int main() {
    char fileName[50];
    printf("Enter the name of file to encrypt: ");
    scanf("%s", fileName);

    FILE *fp1 = fopen(fileName, "r");
    if(fp1 == NULL) {
        printf("Unable to open file!");
        exit(1);
    }

    FILE *fp2 = fopen("encryptedFile.txt", "w+");
    
    encryptFileContent(fp1, fp2); // Encryption process

    fclose(fp1);
    fclose(fp2);

    printf("File encrypted successfully");

    return 0;
}

void encryptFileContent(FILE *fp1, FILE *fp2) {
        char buffer[100];

        while(fgets(buffer, 100, fp1)) {
            for(int i = 0; i < strlen(buffer); i++) {
                buffer[i] = buffer[i] + KEY; // Encryption key added to each character
            }
            fputs(buffer, fp2);
        }
}