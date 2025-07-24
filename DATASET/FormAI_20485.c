//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_WORDS 20000

int load_dict(FILE *f, char **dict) {
    int num_words = 0;
    char line[MAX_WORD_LENGTH];

    while (fgets(line, MAX_WORD_LENGTH, f)) {
        // Remove newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';
        dict[num_words++] = strdup(line);
    }

    return num_words;
}

void check_spell(char **dict, int num_words, char *word) {
    int i;
    char lower_word[MAX_WORD_LENGTH];

    // Convert to lowercase
    for (i = 0; i < strlen(word); i++)
        lower_word[i] = tolower(word[i]);
    lower_word[i] = '\0';

    // Check if word is in dictionary
    for (i = 0; i < num_words; i++)
        if (strcmp(dict[i], lower_word) == 0) return;

    printf("Did you mean:\n");

    // Check one edit distance away
    for (i = 0; i < num_words; i++) {
        int j, diff = 0;

        // Check deletion
        for (j = 0; dict[i][j]; j++) {
            if (lower_word[j+diff] == '\0' || dict[i][j] != lower_word[j+diff]) {
                diff++;
                if (diff > 1) break;
            }
        }

        if (diff <= 1) {
            printf("- %s\n", dict[i]);
            continue;
        }

        // Check substitution
        diff = 0;
        for (j = 0; dict[i][j]; j++) {
            if (lower_word[j] == '\0' || dict[i][j] != lower_word[j]) {
                diff++;
                if (diff > 1) break;
            }
        }

        if (diff <= 1) {
            printf("- %s\n", dict[i]);
            continue;
        }

        // Check insertion
        diff = 0;
        for (j = 0; lower_word[j]; j++) {
            if (dict[i][j+diff] != lower_word[j]) {
                diff++;
                if (diff > 1) break;
            }
        }

        if (diff <= 1) {
            printf("- %s\n", dict[i]);
            continue;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <dictionary file> <word>\n", argv[0]);
        return 1;
    }

    char *dict[MAX_DICT_WORDS];
    int num_words;
    FILE *f = fopen(argv[1], "r");

    if (!f) {
        printf("Could not open dictionary file.\n");
        return 1;
    }

    num_words = load_dict(f, dict);
    fclose(f);

    check_spell(dict, num_words, argv[2]);

    return 0;
}