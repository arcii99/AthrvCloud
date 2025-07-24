//FormAI DATASET v1.0 Category: Ebook reader ; Style: calm
#include<stdio.h>
#include<stdlib.h>

#define MAX_CHAR 1000

int main(){
    FILE *fPointer;
    char filePath[MAX_CHAR], fileContent[MAX_CHAR];

    printf("Enter the path of the file to read: ");
    scanf("%s",&filePath);

    fPointer = fopen(filePath,"r");

    if(fPointer == NULL){
        printf("Error: File not found.");
        exit(1);
    }

    printf("\nFile Content:\n\n");

    while(fgets(fileContent, MAX_CHAR, fPointer) != NULL){
        printf("%s",fileContent);
    }

    fclose(fPointer);

    return 0;
}