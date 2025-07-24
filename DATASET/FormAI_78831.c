//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <ctype.h>

int main()
{
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    int inWord = 0;
    int inLineComment = 0;
    int inBlockComment = 0;

    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error: failed to open file\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
            inLineComment = 0;
        }

        if (!inLineComment && !inBlockComment) {
            if (isspace(ch)) {
                inWord = 0;
            } else if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        }

        if (ch == '/') {
            int nextCh = fgetc(fp);
            if (nextCh == '/') {
                inLineComment = 1;
                charCount -= 2;
            } else if (nextCh == '*') {
                inBlockComment = 1;
                charCount -= 2;
            } else {
                fseek(fp, -1, SEEK_CUR);
            }
        } else if (ch == '*') {
            int nextCh = fgetc(fp);
            if (nextCh == '/') {
                inBlockComment = 0;
                charCount--;
            } else {
                fseek(fp, -1, SEEK_CUR);
            }
        }
    }

    fclose(fp);

    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);

    return 0;
}