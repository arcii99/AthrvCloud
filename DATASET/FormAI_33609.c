//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
#include<stdio.h>
#include<string.h>

#define MAX_STR_LEN 1000
#define MAX_WORDS 100

char dict[MAX_WORDS][MAX_STR_LEN];
int num_words = 0;

void read_dictionary() {
    FILE* fp = fopen("dictionary.txt", "r");
    char buffer[MAX_STR_LEN];
    while (fgets(buffer, MAX_STR_LEN, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(dict[num_words], buffer);
        num_words++;
    }
    fclose(fp);
}

int is_valid_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(dict[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char* sentence) {
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        if (!is_valid_word(word)) {
            printf("MISSPELLED WORD: %s\n", word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    read_dictionary();
    char sentence[MAX_STR_LEN];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_STR_LEN, stdin);
    check_spelling(sentence);
    return 0;
}