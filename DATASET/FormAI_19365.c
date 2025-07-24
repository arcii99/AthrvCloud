//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 10000

struct Dictionary {
    char word[MAX_WORD_LEN];
    int frequency;
};

struct Dictionary createDictionary() {
    struct Dictionary dict;
    strcpy(dict.word, "");
    dict.frequency = 0;
    return dict;
}

void toLowerCase(char* word) {
    int i = 0;
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }
}

int isWordInDictionary(char* word, struct Dictionary* dictArr, int dictSize) {
    int i;
    for (i = 0; i < dictSize; i++) {
        if (strcmp(dictArr[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void sortDictionary(struct Dictionary* dictArr, int dictSize) {
    int i, j;
    struct Dictionary temp;
    for (i = 0; i < dictSize; i++) {
        for (j = i+1; j < dictSize; j++) {
            if (strcmp(dictArr[i].word, dictArr[j].word) > 0) {
                temp = dictArr[i];
                dictArr[i] = dictArr[j];
                dictArr[j] = temp;
            }
        }
    }
}

void printDictionary(struct Dictionary* dictArr, int dictSize) {
    int i;
    for (i = 0; i < dictSize; i++) {
        printf("%s - %d\n", dictArr[i].word, dictArr[i].frequency);
    }
}

int main() {
    FILE *fp;
    char word[MAX_WORD_LEN];
    int dictSize = 0, index, i;

    // Create dictionary array
    struct Dictionary dict[MAX_DICT_WORDS];
    for (i = 0; i < MAX_DICT_WORDS; i++) {
        dict[i] = createDictionary();
    }

    // Open dictionary file
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file\n");
        exit(1);
    }

    // Read words from dictionary file and add to dictionary array
    while (fscanf(fp, "%s", word) != EOF) {
        toLowerCase(word);
        index = isWordInDictionary(word, dict, dictSize);
        if (index == -1) {
            strcpy(dict[dictSize].word, word);
            dict[dictSize].frequency = 1;
            dictSize++;
        } else {
            dict[index].frequency++;
        }
    }

    // Close dictionary file
    fclose(fp);

    // Sort dictionary array alphabetically
    sortDictionary(dict, dictSize);

    // Print dictionary array
    printf("Dictionary:\n");
    printDictionary(dict, dictSize);

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open input file\n");
        exit(1);
    }

    // Read words from input file and check if they are in dictionary array
    printf("Misspelled Words:\n");
    while (fscanf(fp, "%s", word) != EOF) {
        toLowerCase(word);
        index = isWordInDictionary(word, dict, dictSize);
        if (index == -1) {
            printf("%s\n", word);
        }
    }

    // Close input file
    fclose(fp);

    return 0;
}