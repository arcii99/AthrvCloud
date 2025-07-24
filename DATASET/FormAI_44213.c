//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    // opening the file in write mode
    FILE *fptr = fopen("sample.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // writing data to the file
    fprintf(fptr, "Hello World!\n");
    fprintf(fptr, "This is a sample file.\n");

    // closing the file
    fclose(fptr);

    // opening the file in read mode
    fptr = fopen("sample.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // reading data from the file
    char buffer[255];
    while (fgets(buffer, 255, fptr) != NULL) {
        printf("%s", buffer);
    }

    // closing the file
    fclose(fptr);

    return 0;
}