//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX 1000

void encryptFile(char *fileName) {
    FILE *file = fopen(fileName, "r+");
    char buffer[MAX];
    if(file == NULL) {
        printf("Error opening file!");
        return;
    }
    while(fgets(buffer, MAX, file)) {
        int length = strlen(buffer);
        for(int i=0; i<length; i++) {
            buffer[i] = buffer[i] + 1; // encrypting by shifting each character by 1 ASCII value
        }
        fseek(file, -length, SEEK_CUR);
        fputs(buffer, file);
    }
    fclose(file);
}

int main() {
    char fileName[MAX];
    printf("Enter file name: ");
    fgets(fileName, MAX, stdin);
    fileName[strcspn(fileName, "\n")] = 0; // removing the newline character from user input
    encryptFile(fileName);
    printf("File encrypted successfully.");
    return 0;
}