//FormAI DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    FILE *fp;

    printf("Enter the name of the Ebook file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: Unable to open the file.");
        exit(EXIT_FAILURE);
    }

    char c;
    while((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}