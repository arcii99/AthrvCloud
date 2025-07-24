//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fp;

    // Open file for reading
    fp = fopen("does_not_exist.txt", "r");

    if (fp == NULL) {
        // Print error message and exit if file cannot be opened
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // File has been successfully opened, so read its contents
    char c = fgetc(fp);

    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}