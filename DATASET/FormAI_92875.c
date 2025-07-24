//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    // create a FILE pointer for read/write operations
    FILE *fp;
    char filename[50];
    char buffer[1000];

    // prompt user for filename
    printf("Enter the file name: ");
    fgets(filename, 50, stdin);

    // clear newline character from filename
    char *pos;
    if ((pos = strchr(filename, '\n')) != NULL) {
        *pos = '\0';
    }

    // create file
    fp = fopen(filename, "w+");

    // check if file was created successfully
    if (fp == NULL) {
        printf("Error creating file.");
        return -1;
    }

    // write to file
    fprintf(fp, "This is a test line.\n");

    // read from file
    rewind(fp);
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    // close file
    fclose(fp);

    return 0;
}