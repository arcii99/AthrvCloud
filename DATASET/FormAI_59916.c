//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given file is a virus
int isVirus(char* fileName) {
    // Sample virus string
    char* virusString = "VIRUS";
    // Open the file
    FILE* fileHandle = fopen(fileName, "r");
    // Check if the file could be opened
    if (fileHandle == NULL) {
        printf("Could not open file: %s\n", fileName);
        return 0;
    }
    // Read the contents of the file
    char buffer[100];
    while (fgets(buffer, sizeof buffer, fileHandle)) {
        // Check if the virus string is present in the buffer
        if (strstr(buffer, virusString) != NULL) {
            fclose(fileHandle);
            return 1;
        }
    }
    fclose(fileHandle);
    return 0;
}

int main() {
    // Sample list of files
    char* fileList[] = {"file1", "file2", "file3", "file4", "file5"};
    // Traverse through the list of files and check for each file if it is a virus
    int i;
    for (i = 0; i < 5; i++) {
        if (isVirus(fileList[i]))
            printf("%s is a virus\n", fileList[i]);
        else
            printf("%s is not a virus\n", fileList[i]);
    }
    return 0;
}