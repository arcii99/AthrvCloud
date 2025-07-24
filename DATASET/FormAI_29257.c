//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// function to read a word from input
int read_word(char *word, int max_word_len) {
    int c, len = 0;
    while ((c = getchar()) != EOF && !isalpha(c));
    if (c == EOF) return 0;
    word[len++] = c;
    while ((c = getchar()) != EOF && --max_word_len > 1) {
        if (isalpha(c)) {
            word[len++] = c;
        } else {
            break;
        }
    }
    word[len] = '\0';
    return len;
}

// function to load the dictionary file into memory
char **load_dictionary(const char *filename, int *num_words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return NULL;

    // count number of words in dictionary
    int count = 0;
    char tmp[128];
    while (fgets(tmp, sizeof(tmp), fp) != NULL) {
        count++;
    }
    rewind(fp);
    *num_words = count;

    // allocate memory for dictionary
    char **dict = malloc(count * sizeof(char *));
    int i = 0;
    while (fgets(tmp, sizeof(tmp), fp) != NULL) {
        int len = strlen(tmp);
        if (len > 0 && tmp[len-1] == '\n') {
            tmp[len-1] = '\0';
        }
        dict[i] = malloc(len * sizeof(char));
        strncpy(dict[i], tmp, len);
        i++;
    }
    fclose(fp);
    return dict;
}

// function to check if a word is in the dictionary
int check_word(const char *word, char **dict, int num_words) {
    int lo = 0, hi = num_words - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cmp = strcmp(word, dict[mid]);
        if (cmp == 0) {
            return 1; // found word in dictionary
        } else if (cmp < 0) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return 0; // word not in dictionary
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }
    char **dict;
    int num_words;
    dict = load_dictionary(argv[1], &num_words);
    if (dict == NULL) {
        printf("Error: could not load dictionary file '%s'\n", argv[1]);
        return 1;
    }
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error: could not open text file '%s'\n", argv[2]);
        return 1;
    }
    char word[128];
    while (read_word(word, sizeof(word)) > 0) {
        if (!check_word(word, dict, num_words)) {
            printf("Spelling error: %s\n", word);
        }
    }
    fclose(fp);
    for (int i = 0; i < num_words; i++) {
        free(dict[i]);
    }
    free(dict);
    return 0;
}