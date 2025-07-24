//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100];
    FILE *fptr;

    // Open file for writing
    fptr = fopen("sample.txt", "w");

    if (fptr == NULL) {
        printf("File could not be opened.");
        exit(1);
    }

    // Write to file
    printf("Enter a string to write to file: ");
    fgets(str, sizeof(str), stdin);

    fprintf(fptr, "%s", str);

    fclose(fptr);

    // Open file for reading
    fptr = fopen("sample.txt", "r");

    if (fptr == NULL) {
        printf("File could not be opened.");
        exit(1);
    }

    // Read and print file contents
    printf("\nFile contents:\n");
    while (fgets(str, sizeof(str), fptr) != NULL) {
        printf("%s", str);
    }

    fclose(fptr);

    return 0;
}