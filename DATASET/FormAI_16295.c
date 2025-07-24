//FormAI DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 50
#define DICTIONARY_LEN 10
#define MAX_MISSPELLED 5

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int length;
} dictionary_t;

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int misspelled;
} word_t;

char* toLowerCase(char* word) {
    for(int i=0; i<strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

void checkWords(word_t *words, dictionary_t *dictionary, int numWords) {
    for(int i=0; i<numWords; i++) {
        words[i].misspelled = 1;
        for(int j=0; j<DICTIONARY_LEN; j++) {
            if(strcmp(toLowerCase(words[i].word), toLowerCase(dictionary[j].word)) == 0) {
                words[i].misspelled = 0;
                break;
            }
        }
    }
}

int main() {
    dictionary_t dictionary[DICTIONARY_LEN] = {
        {"hello", strlen("hello")},
        {"world", strlen("world")},
        {"dictionary", strlen("dictionary")},
        {"misspelled", strlen("misspelled")},
        {"programming", strlen("programming")},
        {"language", strlen("language")},
        {"computer", strlen("computer")},
        {"science", strlen("science")},
        {"algorithm", strlen("algorithm")},
        {"variable", strlen("variable")}
    };

    word_t words[MAX_MISSPELLED] = {
        {"Hello", 1},
        {"WORld", 1},
        {"dicshunery", 1},
        {"programmin", 1},
        {"VARable", 1}
    };

    checkWords(words, dictionary, MAX_MISSPELLED);

    for(int i=0; i<MAX_MISSPELLED; i++) {
        if(words[i].misspelled) {
            printf("%s is misspelled\n", words[i].word);
        }
    }
    return 0;
}