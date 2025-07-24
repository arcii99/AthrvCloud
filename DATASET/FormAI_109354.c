//FormAI DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please enter the file name.\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    char *words[MAX_WORDS];
    int wordCount[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        wordCount[i] = 0;
    }

    char line[MAX_WORD_LENGTH];
    int count = 0;
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        char *word = strtok(line, " ,\n");
        while (word != NULL) {
            for (int i = 0; word[i]; i++){
                word[i] = tolower(word[i]);
            }

            int i;
            for (i = 0; i < count; i++) {
                if (strcmp(word, words[i]) == 0) {
                    wordCount[i]++;
                    break;
                }
            }
            if (i == count) {
                words[count] = (char *) malloc((strlen(word) + 1) * sizeof(char));
                strcpy(words[count], word);
                wordCount[count]++;
                count++;
            }

            word = strtok(NULL, " ,\n");
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s : %d\n", words[i], wordCount[i]);
        free(words[i]);
    }

    fclose(file);
    return 0;
}