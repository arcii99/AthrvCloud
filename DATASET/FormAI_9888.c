//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 500
#define MAX_DICTIONARY_ENTRIES 50

struct DictionaryEntry {
    char* catWord;
    char* englishTranslation;
};

void addEntry(struct DictionaryEntry* dictionary, char* cat, char* english, int* numEntries) {
    if (*numEntries < MAX_DICTIONARY_ENTRIES) {
        dictionary[*numEntries].catWord = strdup(cat);
        dictionary[*numEntries].englishTranslation = strdup(english);
        *numEntries += 1;
    }
    else {
        printf("Maximum dictionary entries reached!\n");
    }
}

char* translate(struct DictionaryEntry* dictionary, int numEntries, char* input) {
    char* translated = malloc(MAX_OUTPUT_LENGTH * sizeof(char));
    translated[0] = '\0';
    char* token = strtok(input, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < numEntries; i++) {
            if (strcmp(token, dictionary[i].catWord) == 0) {
                strcat(translated, dictionary[i].englishTranslation);
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translated, token);
        }
        strcat(translated, " ");
        token = strtok(NULL, " ");
    }
    return translated;
}

int main(void) {
    struct DictionaryEntry dictionary[MAX_DICTIONARY_ENTRIES];
    int numEntries = 0;
    addEntry(dictionary, "meow", "hello", &numEntries);
    addEntry(dictionary, "purr", "thank you", &numEntries);
    addEntry(dictionary, "hiss", "go away", &numEntries);
    addEntry(dictionary, "sniff", "what", &numEntries);

    char input[MAX_INPUT_LENGTH];
    printf("Enter a sentence in cat language:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strlen(input)-1] = '\0';

    char *translated = translate(dictionary, numEntries, input);
    printf("%s\n", translated);
    free(translated);

    return 0;
}