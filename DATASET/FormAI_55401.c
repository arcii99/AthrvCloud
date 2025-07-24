//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;
    char fileName[] = "introspection.txt";
    char textToWrite[] = "This program uses introspection to write to a file.\n";
    char readBuffer[50];
    
    // Open file for writing
    filePointer = fopen(fileName, "w");
    
    // Write text to file
    fprintf(filePointer, "%s", textToWrite);
    
    // Close file
    fclose(filePointer);
    
    // Open file for reading
    filePointer = fopen(fileName, "r");
    
    // Display contents of file
    if (filePointer == NULL) {
        printf("Error opening file");
        exit(1);
    }
    
    while (fgets(readBuffer, 50, filePointer)) {
        printf("%s", readBuffer);
    }
    
    // Close file
    fclose(filePointer);
    
    return 0;
}