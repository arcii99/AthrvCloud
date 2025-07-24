//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>

#define TAB 4 // Define tab size

int main()
{
    FILE *inputFile, *outputFile;
    char ch;
    int numSpaces = 0;

    inputFile = fopen("input.html", "r"); // Open input file

    if (inputFile == NULL) { // Check if file exists
        printf("File not found!");
        return 1;
    }

    outputFile = fopen("output.html", "w"); // Open output file

    if (outputFile == NULL) { // Check if file can be created
        printf("Unable to create output file!");
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == '<') {
            fputc(ch, outputFile);
            numSpaces += TAB; // Increase indent level
        } else if (ch == '>') {
            fputc(ch, outputFile);
            numSpaces -= TAB; // Decrease indent level
        } else if (ch == '\n') {
            fputc(ch, outputFile);
            for (int i = 0; i < numSpaces; i++) { // Insert spaces to align under tag
                fputc(' ', outputFile);
            }
        } else if (ch == ' ' && numSpaces > 0) { 
            fputc(ch, outputFile);
        } else { // For any other character
            fputc(ch, outputFile);
        }
    }

    fclose(inputFile); // Close both files
    fclose(outputFile);

    printf("HTML file beautified successfully!");
    return 0;
}