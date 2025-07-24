//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removePunctuation(char *string) {
    char *newString = malloc(strlen(string) + 1);
    int i, j = 0;
    for (i = 0; i < strlen(string); i++) {
        if (isalpha(string[i])) {
            newString[j++] = tolower(string[i]);
        }
    }
    newString[j] = '\0';
    return newString;
}

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *fp = fopen("dictionary.txt", "r");
    char word[25];
    char **dictionary = (char **)malloc(234936 * sizeof(char *));
    int i = 0;
    while (fgets(word, 25, fp)) {
        dictionary[i] = removePunctuation(word);
        i++;
    }
    qsort(dictionary, i, sizeof(char *), compare);
    fclose(fp);

    printf("Enter a sentence: ");
    char sentence[100];
    fgets(sentence, 100, stdin);
    char *token = strtok(sentence, " ,.\n\0");

    while (token) {
        char *wordToCheck = removePunctuation(token);
        if (bsearch(&wordToCheck, dictionary, i, sizeof(char *), compare) == NULL) {
            printf("%s is spelled incorrectly.\n", token);
        }
        token = strtok(NULL, " ,.\n\0");
        free(wordToCheck);
    }

    free(dictionary);
    return 0;
}