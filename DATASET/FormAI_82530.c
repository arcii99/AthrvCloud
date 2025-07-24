//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variables for file operations
    FILE *fp;
    char filename[] = "example.xml";
    char ch;

    // Open file for reading
    fp = fopen(filename, "r");

    // Check for errors in opening file
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    // Variable for storing XML element
    char element[20];

    // Loop through file character by character
    while ((ch = fgetc(fp)) != EOF) {
        // Check for start of element
        if (ch == '<') {
            // Reset element string
            int i = 0;
            element[i] = '\0';
            // Read element name
            while ((ch = fgetc(fp)) != '>') {
                element[i++] = ch;
            }
            // Add null terminator to end of element string
            element[i] = '\0';
            // Print element
            printf("Element: %s\n", element);
        }
    }

    // Close file
    fclose(fp);

    return 0;
}