//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int wordCount = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            wordCount++;
        }
    }

    fclose(fp);

    printf("Number of words in %s = %d\n", filename, wordCount);

    return 0;
}