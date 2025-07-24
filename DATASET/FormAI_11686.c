//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>

// function to count the number of lines in a file
int countLines(FILE *file) {
    char ch;
    int count = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    rewind(file); // resets file pointer to beginning of file
    return count;
}

int main() {
    FILE *filePointer;
    char fileName[50];
    char line[100];
    int numLines;

    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r"); // open file in read mode

    if (filePointer == NULL) {
        printf("Unable to open file. Please check your filename and try again.\n");
        return 0;
    }

    numLines = countLines(filePointer);
    printf("The file contains %d lines.\n", numLines);

    // read and print each line
    printf("File contents:\n");
    for (int i = 0; i < numLines; i++) {
        fgets(line, 100, filePointer);
        printf("%s", line);
    }

    fclose(filePointer); // close file
    return 0;
}