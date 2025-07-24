//FormAI DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;
    char fileName[20], data[100];
    int ch, count, i;

    printf("Enter the name of the file to create: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "w");

    printf("Enter data into the file. Press Ctrl + D to stop.\n\n");

    while ((ch = getchar()) != EOF) {
        putc(ch, filePointer);
    }

    fclose(filePointer);

    printf("\n%s created and saved successfully.\n", fileName);

    printf("\nReading file contents.\n\n");

    filePointer = fopen(fileName, "r");

    while ((ch = fgetc(filePointer)) != EOF) {
        putchar(ch);
    }

    fclose(filePointer);

    printf("\nFile read successful.\n");

    return 0;
}