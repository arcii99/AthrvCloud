//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main(){
    char sourceName[50], destinationName[50];
    FILE *sourceFile, *destinationFile;
    char data[BUFFER_SIZE];
    int count;

    printf("Enter the source file name: ");
    scanf("%s", sourceName);

    sourceFile = fopen(sourceName, "r");

    if(!sourceFile){
        printf("\n\nError: File cannot be opened\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter the destination file name: ");
    scanf("%s", destinationName);

    destinationFile = fopen(destinationName, "w");

    if(!destinationFile){
        printf("\n\nError: File cannot be opened\n");
        exit(EXIT_FAILURE);
    }

    while((count = fread(data, BUFFER_SIZE, 1, sourceFile))){
        fwrite(data, BUFFER_SIZE, 1, destinationFile);
    }

    printf("\n\n%s file backed up successfully to %s\n", sourceName, destinationName);

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}