//FormAI DATASET v1.0 Category: File handling ; Style: distributed
#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fileptr1, *fileptr2;
    char filename[100], c;

    printf("Enter the filename to open for reading \n");
    scanf("%s", filename);

    fileptr1 = fopen(filename, "r");
    if (fileptr1 == NULL) {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    printf("Enter the filename to open for writing \n");
    scanf("%s", filename);

    fileptr2 = fopen(filename, "w");
    if (fileptr2 == NULL) {
        printf("Cannot create file %s \n", filename);
        exit(0);
    }

    // Read contents from file
    c = fgetc(fileptr1);
    while (c != EOF) {
        fputc(c, fileptr2);
        c = fgetc(fileptr1);
    }

    printf("\nContents copied to %s", filename);

    fclose(fileptr1);
    fclose(fileptr2);
    return 0;
}