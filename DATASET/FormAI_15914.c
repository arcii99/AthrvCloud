//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>

int main() {
    // Open file for writing
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Write data to file
    fprintf(fp, "Hello, world!\n");
    fprintf(fp, "This is a file handling example program.\n");

    // Close file
    fclose(fp);

    // Open file for reading
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    // Read data from file
    char buffer[50];
    while (!feof(fp)) {
        fgets(buffer, 50, fp);
        printf("%s", buffer);
    }

    // Close file
    fclose(fp);

    return 0;
}