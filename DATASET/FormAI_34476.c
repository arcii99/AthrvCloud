//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch, fileName[50];

    printf("Enter the name of the file to read:\n");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    printf("Successfully opened file %s\n", fileName);

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}