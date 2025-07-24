//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    fp = fopen("sample.txt", "r");

    if(fp==NULL) {
        printf("File does not exist.\n");
        exit(1);
    }

    while((ch=getc(fp))!=EOF) {
        if(ch!=' ' && ch!='\t') {
            charCount++;
        }

        if(ch==' ' || ch=='\t' || ch=='\n') {
            wordCount++;
        }

        if(ch=='\n') {
            lineCount++;
        }
    }

    fclose(fp);

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}