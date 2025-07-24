//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

void trim(char *word) {
    char *p = word + strlen(word) - 1;
    while (isspace(*p)) {
        *p = '\0';
        p--;
    }
}

int is_valid_word(char *word) {
    int length = strlen(word);
    if (length > MAX_WORD_LEN) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void print_word(char *word, int line_num) {
    printf("Line %d: %s\n", line_num, word);
}

void check_spelling(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    int line_num = 1;
    while (getline(&line, &len, fp) != -1) {
        char *word = strtok(line, " ,.-\n");
        while (word) {
            trim(word);
            if (is_valid_word(word)) {
                print_word(word, line_num);
            }
            word = strtok(NULL, " ,.-\n");
        }
        line_num++;
    }
    free(line);
}

int main() {
    FILE *fp = fopen("spellcheck.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    check_spelling(fp);
    fclose(fp);
    return 0;
}