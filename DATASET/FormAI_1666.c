//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    printf("Welcome to Data Recovery Tool - The happiest place for recovering lost data!\n");
    char filename[50], extension[5];
    printf("Please enter the name of the file you want to recover: ");
    scanf("%s", filename);
    printf("Please enter the file type extension (e.g. txt, docx): ");
    scanf("%s", extension);
    char recoveryName[50];
    strcpy(recoveryName, filename);
    strcat(recoveryName, ".recovered");
    FILE *fp, *fpRecovered;
    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Oops! Unable to open the file, please check the file name and try again.");
        exit(1);
    }
    fpRecovered = fopen(recoveryName, "wb");
    if(fpRecovered == NULL){
        printf("Oops! Unable to create a recovered file, please check the location and try again.");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    int n;
    while((n = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0){
        fwrite(buffer, sizeof(char), n, fpRecovered);
    }
    printf("Your file has been recovered successfully! You can find it with the name %s in the same location.\n", recoveryName);
    fclose(fp);
    fclose(fpRecovered);
    return 0;
}