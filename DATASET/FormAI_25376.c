//FormAI DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORD_LEN 50

int main() {
    // Open the dictionary file
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Failed to open dictionary file.\n");
        return 1;
    }

    // Read the dictionary file into a hash table
    char dict_word[WORD_LEN];
    int num_buckets = 10000;
    char *word_table[num_buckets];
    memset(word_table, 0, sizeof(word_table));
    while (fgets(dict_word, WORD_LEN, dict_file)) {
        // Remove the newline character at the end of the string (if present)
        int dict_len = strlen(dict_word);
        if (dict_word[dict_len - 1] == '\n') {
            dict_word[dict_len - 1] = '\0';
        }

        // Hash the word and store it in the hash table
        int hash_val = 0;
        for (int i = 0; i < dict_len; i++) {
            hash_val = (hash_val * 31 + tolower(dict_word[i])) % num_buckets;
        }
        word_table[hash_val] = dict_word;
    }
    fclose(dict_file);

    // Prompt the user to enter a sentence for spell checking
    printf("Enter a sentence to check for spelling errors:\n");
    char sentence[1000];
    fgets(sentence, 1000, stdin);

    // Tokenize the sentence into words and check each word against the hash table
    char *word = strtok(sentence, " ,.\n");
    while (word != NULL) {
        int word_len = strlen(word);
        int hash_val = 0;
        for (int i = 0; i < word_len; i++) {
            hash_val = (hash_val * 31 + tolower(word[i])) % num_buckets;
        }
        char *match = word_table[hash_val];
        if (match != NULL && strcasecmp(match, word) != 0) {
            printf("Error: %s is misspelled. Did you mean %s?\n", word, match);
        }
        word = strtok(NULL, " ,.\n");
    }

    return 0;
}