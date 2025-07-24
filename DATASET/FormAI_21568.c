//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[20];
    char ch;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // open the file for writing
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("Enter some text into the file: \n");
    while ((ch = getchar()) != EOF) {
        fputc(ch, fp);
    }

    fclose(fp);
    printf("\nFile has been written successfully.\n");

    // open the file again for reading
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("\nThe contents of the file are:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
    printf("\nFile has been closed.\n");

    return 0;
}