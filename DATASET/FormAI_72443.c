//FormAI DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50

/**
 * Struct defining a word in the dictionary
 */
typedef struct _word {
    char *text;
    int len;
    struct _word *next;
} Word;

/**
 * Struct defining a node in the hash table
 */
typedef struct _hashnode {
    char key;
    Word *wordlist;
} HashNode;

/**
 * Function to create a new word
 */
Word *new_word(char *text, int len) {
    Word *new_word = malloc(sizeof(Word));
    new_word->text = text;
    new_word->len = len;
    new_word->next = NULL;
    return new_word;
}

/**
 * Function to add a word to the dictionary
 */
void add_word_to_dict(HashNode *ht, char *text, int len) {
    int hashval = tolower(text[0]) - 'a';
    Word *new_word_node = new_word(text, len);
    if (ht[hashval].wordlist == NULL) {
        ht[hashval].wordlist = new_word_node;
        return;
    }
    Word *curr = ht[hashval].wordlist;
    Word *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->text, text) == 0) {
            free(new_word_node);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = new_word_node;
}

/**
 * Function to check if a word exists in the dictionary
 */
int is_word_present(HashNode *ht, char *word) {
    int hashval = tolower(word[0]) - 'a';
    Word *curr = ht[hashval].wordlist;
    while (curr != NULL) {
        if (strcmp(curr->text, word) == 0) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

/**
 * Function to check if a character is a valid letter
 */
int is_alpha_valid(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * Function to get the length of a word
 */
int get_word_len(char *text, int start) {
    int len = 0;
    while (is_alpha_valid(text[start + len])) {
        len++;
    }
    return len;
}

/**
 * Function to check if a word is spelled correctly
 */
void check_word(HashNode *ht, char *text, int start) {
    if (is_word_present(ht, &text[start])) {
        printf("%.*s ", get_word_len(text, start), &text[start]);
    } else {
        printf("[%.*s] ", get_word_len(text, start), &text[start]);
    }
}

/**
 * Function to spell check a sentence
 */
void spell_check_sentence(HashNode *ht, char *sentence) {
    int len = strlen(sentence);
    int i = 0;
    while (i < len) {
        if (!is_alpha_valid(sentence[i])) {
            printf("%c", sentence[i]);
            i++;
            continue;
        }
        int word_len = get_word_len(sentence, i);
        check_word(ht, sentence, i);
        i += word_len;
    }
}

/**
 * Function to clean up the dictionary
 */
void cleanup_dict(HashNode *ht) {
    for (int i = 0; i < 26; i++) {
        Word *curr = ht[i].wordlist;
        while (curr != NULL) {
            Word *next = curr->next;
            free(curr->text);
            free(curr);
            curr = next;
        }
    }
}

/**
 * Main function
 */
int main() {
    char *dict_words[] = { "hello", "world", "this", "is", "a", "test", "program" };
    HashNode ht[26] = { 0 };
    for (int i = 0; i < 7; i++) {
        add_word_to_dict(ht, dict_words[i], strlen(dict_words[i]));
    }
    char *test_sentence = "Hello, world! This is a test program.";
    printf("Input sentence: %s\n", test_sentence);
    printf("Output sentence: ");
    spell_check_sentence(ht, test_sentence);
    printf("\n");
    cleanup_dict(ht);
    return 0;
}