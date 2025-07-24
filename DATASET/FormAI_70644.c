//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/* Define a boolean type */
typedef bool Boolean;

/* Define the maximum number of words allowed */
#define MAX_ENTRIES 1000
/* Define the maximum length of a word */
#define MAX_WORD_LEN 50

/* Define a structure to represent a word */
typedef struct {
    char text[MAX_WORD_LEN + 1];
    int count;
} Word;

/* Define an array to store instances of words */
Word entries[MAX_ENTRIES];
/* Define the index into the entries array */
int num_entries = 0;

/* Function prototypes */
Boolean is_word_char(char);
int find_entry(char*);
void add_entry(char*);
void to_lower_case(char*);

int main() {
    char input[1000];
    char *word_start, *p;

    printf("Enter text: \n");
    fgets(input, sizeof(input), stdin);

    word_start = NULL;
    for (p = input; *p != '\0'; ++p) {
        if (is_word_char(*p)) {
            if (word_start == NULL) {
                word_start = p;
            }
        } else {
            if (word_start != NULL) {
                *p = '\0';
                add_entry(word_start);
                word_start = NULL;
            }
        }
    }

    /* Check for an unfinished word */
    if (word_start != NULL) {
        add_entry(word_start);
    }

    /* Display the results */
    printf("Word Frequency Count: \n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %d\n", entries[i].text, entries[i].count);
    }

    return 0;
}

/**
 * Determines whether a character is part of a word.
 * A character is part of a word if it is an alphabetical character or an apostrophe.
 *
 * @param ch: the character to check
 * @returns true if the character is part of a word; otherwise, false
 */
Boolean is_word_char(char ch) {
    return isalpha(ch) || ch == '\'';
}

/**
 * Finds an entry in the entries array based on a word.
 *
 * @param word: the word to search for
 * @returns the index into the entries array for the entry, or -1 if the word is not found
 */
int find_entry(char* word) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].text, word) == 0) {
            return i;
        }
    }

    /* Word not found */
    return -1;
}

/**
 * Adds an entry to the entries array based on a word.
 * If the entry already exists, its count is incremented.
 *
 * @param word: the word to add
 */
void add_entry(char* word) {
    int index = find_entry(word);
    if (index != -1) {
        entries[index].count++;
    } else {
        if (num_entries == MAX_ENTRIES) {
            printf("Error: Maximum number of entries exceeded\n");
            return;
        }
        strcpy(entries[num_entries].text, word);
        entries[num_entries].count = 1;
        num_entries++;
    }
}

/**
 * Converts a string to lowercase.
 *
 * @param str: the string to convert
 */
void to_lower_case(char* str) {
    for (char* p = str; *p != '\0'; ++p) {
        *p = tolower(*p);
    }
}