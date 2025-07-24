//FormAI DATASET v1.0 Category: File handling ; Style: introspective
/* A unique C program demonstrating file handling using introspection */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[50];  // to store the filename
    FILE *fp;           // file pointer

    printf("Please enter the filename to create or open: ");
    scanf("%s", filename);

    fp = fopen(filename, "w+");    // attempt to open the file in write+ mode

    if (fp == NULL) {       // if file was not successfully opened
        printf("Error: File could not be opened.\n");
        exit(1);        // exit the program with error code 1
    }

    // introspect the file pointer
    printf("File pointer address: %p\n", fp);
    printf("File pointer file descriptor: %d\n", fileno(fp));
    printf("Current file position: %ld\n", ftell(fp));

    // write something to the file
    fputs("Hello, world!", fp);

    // introspect the file pointer again
    printf("New file position: %ld\n", ftell(fp));

    // close the file
    fclose(fp);

    return 0;
}