//FormAI DATASET v1.0 Category: Error handling ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main() {
    FILE *filePointer;
    char fileName[] = "example.txt";
    
    filePointer = fopen(fileName, "r");
    
    if (filePointer == NULL) {
        
        if(errno == ENOENT) {
            printf("The file %s does not exist.\n", fileName);
        } else if(errno == EACCES) {
            printf("The file %s cannot be opened due to permission issues.\n", fileName);
        } else if(errno == ENOMEM) {
            printf("Memory allocation failed while opening the file %s.\n", fileName);
        } else {
            printf("An unknown error occurred while opening the file %s.\n", fileName);
        }
        exit(EXIT_FAILURE);
    }
    
    printf("The file %s has been opened successfully!\n", fileName);
    
    // Some code here to read the file
    
    if (fclose(filePointer) != 0) {
        printf("An unknown error occurred while closing the file %s.\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    printf("The file %s has been closed successfully!\n", fileName);
    return 0;
}