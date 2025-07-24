//FormAI DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 50000

typedef struct Dictionary {
    char word[MAX_WORD_LEN];
} Dictionary;

Dictionary dict[MAX_DICT_WORDS];

// Function to load dictionary into an array
void loadDictionary(FILE *fp) {
    int i = 0;
    char line[MAX_WORD_LEN];

    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        line[strlen(line)-1] = '\0';
        strcpy(dict[i].word, line);
        i++;
    }
}

// Function to check if given word is present in the dictionary
int isWordInDictionary(char *word) {
    int left = 0, right = MAX_DICT_WORDS - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (strcmp(word, dict[mid].word) == 0) {
            return 1;
        }
        else if (strcmp(word, dict[mid].word) < 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return 0;
}

// Function to check if given character is punctuation or not
int isPunctuation(char ch) {
    if (ispunct(ch) || ch == '’' || ch == '‘') {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to spellcheck a given text file
void spellcheck(FILE *fp) {
    char line[MAX_WORD_LEN];
    int lineCount = 0;
    int errorsFound = 0;

    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        lineCount++;
        char *word = strtok(line, " \n");

        while (word != NULL) {
            for (int i = 0; i < strlen(word); i++) {
                if (isalpha(word[i]) == 0 && isPunctuation(word[i]) == 0) {
                    printf("%s:%d: %s is not a valid word\n", "file.txt", lineCount, word);
                    errorsFound++;
                    break;
                }
                else {
                    word[i] = tolower(word[i]);
                }
            }

            if (errorsFound > 0) {
                break;
            }

            if (isWordInDictionary(word) == 0) {
                printf("%s:%d: %s is misspelled\n", "file.txt", lineCount, word);
                errorsFound++;
            }

            word = strtok(NULL, " \n");
        }

        if (errorsFound > 0) {
            break;
        }
    }

    if (errorsFound == 0) {
        printf("No spelling errors found!\n");
    }
}

int main() {
    // Load dictionary file into array
    FILE *dictFile = fopen("dictionary.txt", "r");

    if (dictFile == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    loadDictionary(dictFile);
    fclose(dictFile);

    // Spellcheck a given text file
    FILE *textFile = fopen("file.txt", "r");

    if (textFile == NULL) {
        printf("Error: Unable to open text file.\n");
        exit(1);
    }

    spellcheck(textFile);
    fclose(textFile);

    return 0;
}