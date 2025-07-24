//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[]){
    char fileName[100];
    char buffer[BUFFER_SIZE];
    FILE *sourceFile, *targetFile;
    int numBytes;
    
    if(argc != 3){
        printf("Usage: ./datarecoverytool <sourcefile> <targetfile>\n");
        exit(1);
    }

    strcpy(fileName, argv[1]);
    sourceFile = fopen(fileName,"rb");

    if(sourceFile == NULL){
        printf("Error: Could not open source file!\n");
        exit(1);
    }

    strcpy(fileName, argv[2]);
    targetFile = fopen(fileName,"wb");

    if(targetFile == NULL){
        printf("Error: Could not open target file!\n");
        exit(1);
    }

    while((numBytes = fread(buffer,sizeof(char),BUFFER_SIZE,sourceFile)) > 0){
        fwrite(buffer,sizeof(char),numBytes,targetFile);
    }

    printf("Data recovery complete!\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}