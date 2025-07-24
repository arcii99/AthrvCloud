//FormAI DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>

int main() {
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL) {
        printf("Unable to open the file for reading!");
        return 0;
    }

    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);

    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL) {
        printf("Unable to open the file for writing!");
        return 0;
    }

    c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("File copied successfully!");

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}