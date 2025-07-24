//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE *filePointer;
    char content[150];

    // Opening file in write mode
    filePointer = fopen("myFile.txt", "w");

    // Checking if file is opened successfully
    if(filePointer == NULL) {
        printf("Unable to create the file\n");
        exit(1);
    }

    // Writing content to the file
    printf("What do you want to write to the file? ");
    scanf("%[^\n]s", content);
    fprintf(filePointer, "%s", content);

    // Closing file
    fclose(filePointer);
    printf("\nFile successfully created and written to!\n\n");

    // Opening file in read mode
    filePointer = fopen("myFile.txt", "r");

    // Checking if file is opened successfully
    if(filePointer == NULL) {
        printf("Unable to read the file\n");
        exit(1);
    }

    // Reading content from the file and displaying it
    printf("\nHere is the content of the file:\n");
    while(fgets(content, 150, filePointer) != NULL) {
        printf("%s", content);
    }

    // Closing file
    fclose(filePointer);
    printf("\nFile successfully read and closed!\n");

    return 0;
}