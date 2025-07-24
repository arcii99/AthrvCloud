//FormAI DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *dict[] = {"apple", "banana", "cherry", "orange", "pear", "pineapple", "watermelon"};
int dict_size = sizeof(dict)/sizeof(char*);

int is_word_in_dict(char *word) {
    int i;
    for (i=0; i<dict_size; i++) {
        if (strcmp(dict[i], word) == 0) return 1;
    }
    return 0;
}

void strip_non_alpha(char *s) {
    int i, j = 0;
    for (i=0; s[i]; i++) {
        if (isalpha(s[i])) s[j++] = tolower(s[i]);
    }
    s[j] = '\0';
}

void check_spelling(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *word = strtok(line, " ,.?!\n");
        while (word) {
            strip_non_alpha(word);
            if (!is_word_in_dict(word)) {
                printf("'%s' is misspelled\n", word);
            }
            word = strtok(NULL, " ,.?!\n");
        }
    }

    fclose(fp);
    if (line) free(line);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    check_spelling(argv[1]);
    return 0;
}