//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

void remove_punctuation(char *word);
void to_lowercase(char *word);
int next_word(FILE *file, char *word);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("error: could not open file \"%s\"\n", argv[1]);
        return 1;
    }

    int count[MAX_WORDS] = {0};
    char words[MAX_WORDS][MAX_WORD_LEN] = {0};
    int num_words = 0;

    char word[MAX_WORD_LEN];
    while(next_word(file, word) && num_words < MAX_WORDS) {
        remove_punctuation(word);
        to_lowercase(word);

        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i], word) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[num_words], word);
            count[num_words] = 1;
            num_words++;
        }
    }

    printf("Word\tFrequency\n");
    printf("----\t---------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i], count[i]);
    }

    fclose(file);
    return 0;
}

void remove_punctuation(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (ispunct(word[i])) {
            for (int j = i; j < len; j++) {
                word[j] = word[j+1];
            }
            len--;
        }
    }
}

void to_lowercase(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

int next_word(FILE *file, char *word) {
    char c;

    // skip past whitespace
    do {
        c = fgetc(file);
    } while (isspace(c) && c != EOF);

    // read in word
    int i = 0;
    while (!isspace(c) && c != EOF && i < MAX_WORD_LEN-1) {
        word[i] = c;
        i++;
        c = fgetc(file);
    }
    word[i] = '\0';

    // handle end of file
    if (i == 0 && c == EOF) {
        return 0;
    }

    return 1;
}