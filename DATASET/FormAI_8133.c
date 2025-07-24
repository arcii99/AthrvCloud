//FormAI DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[20], ch, buffer[50];

    printf("Enter the filename to create or open: ");
    scanf("%s", filename);

    // Open file in append mode
    fp = fopen(filename, "a+");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    // Write to the file
    printf("Enter text to write to file (max 50 characters): ");
    scanf(" %[^\n]", buffer);
    fprintf(fp, "%s\n", buffer);

    // Read from the file
    printf("Contents of the file: \n");
    rewind(fp);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(fp);

    return 0;
}