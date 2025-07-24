//FormAI DATASET v1.0 Category: Spell checking ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 50

void checkWord(char *word);
int getWord(char *word);

int main() {
    char word[MAX_SIZE];
    while (getWord(word)) {
        checkWord(word);
    }
    return 0;
}

int getWord(char *word) {
    int i, c;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            *word++ = tolower(c);
            break;
        }
    }
    for (i = 1; i < MAX_SIZE - 1; i++) {
        if ((c = getchar()) == EOF) {
            break;
        }
        else if (!isalpha(c)) {
            break;
        }
        *word++ = tolower(c);
    }
    *word = '\0';
    if (strlen(word) == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

void checkWord(char *word) {
    FILE *fp;
    char dictionary[MAX_SIZE], line[MAX_SIZE];
    int found = 0;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file \n");
        exit(1);
    }

    while (fgets(line, MAX_SIZE, fp)) {
        sscanf(line, "%s", dictionary);
        if (strcmp(dictionary, word) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("%s is not spelled correctly\n", word);
    }
}