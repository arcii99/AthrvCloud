//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

void to_lowercase(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    int count = 0;
    char word[MAX_WORD_SIZE];
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            word[count++] = ch;
        } else if (count > 0) {
            word[count] = '\0';
            to_lowercase(word);
            printf("%s\n", word);
            count = 0;
        }
    }

    fclose(fp);

    return 0;
}