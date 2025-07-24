//FormAI DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *file;
    char fileName[50];
    printf("Enter the name of the file to open: ");
    scanf("%49s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error");
        exit(errno);
    }

    // Rest of the code goes here
    
    fclose(file);
    return 0;
}