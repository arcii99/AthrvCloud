//FormAI DATASET v1.0 Category: Data recovery tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1000

int main() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *fp;
    long fileSize;
    char *fileContent;

    printf("Enter name of the file to recover: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Unable to open file.");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fileContent = malloc(fileSize);
    if (fileContent == NULL) {
        printf("Memory allocation error.");
        exit(1);
    }

    fread(fileContent, sizeof(char), fileSize, fp);
    fclose(fp);

    printf("Recovered data:\n");
    for (int i = 0; i < fileSize; i++) {
        printf("%c", fileContent[i] ^ 0x55);
    }
    printf("\n");

    free(fileContent);

    return 0;
}