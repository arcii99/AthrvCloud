//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 30 // maximum word length
#define MAX_DICT_ENTRIES 1000 // maximum number of dictionary entries
#define MAX_MISSPELLED_WORDS 100 // maximum number of misspelled words in a document

typedef struct dict_entry_t {
    char word[MAX_WORD_LEN + 1]; // dictionary word
    int count; // number of occurrences in document
} dict_entry_t;

typedef struct misspelled_word_t {
    char word[MAX_WORD_LEN + 1]; // misspelled word
    int line; // line number in document
} misspelled_word_t;

// function prototypes
void to_lower_case(char* str);
bool is_valid_character(char c);
bool is_valid_word(dict_entry_t* dict, int dict_size, char* word);
bool is_in_dictionary(dict_entry_t* dict, int dict_size, char* word, int* index);
void add_to_dictionary(dict_entry_t* dict, int* dict_size, char* word);
void check_document(dict_entry_t* dict, int dict_size, char* document, int document_size, misspelled_word_t* misspelled_words, int* misspelled_word_count);
void print_misspelled_words(misspelled_word_t* misspelled_words, int misspelled_word_count);

int main(int argc, char* argv[]) {
    dict_entry_t dict[MAX_DICT_ENTRIES];
    int dict_size = 0;

    // load dictionary file
    FILE* dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        fprintf(stderr, "Error: could not open dictionary file\n");
        return 1;
    }

    char buffer[MAX_WORD_LEN];
    while (fgets(buffer, MAX_WORD_LEN + 1, dict_file) != NULL) {
        strtok(buffer, "\n"); // remove newline character
        add_to_dictionary(dict, &dict_size, buffer);
    }

    fclose(dict_file);

    // load document file
    FILE* document_file = fopen("document.txt", "r");
    if (document_file == NULL) {
        fprintf(stderr, "Error: could not open document file\n");
        return 1;
    }

    fseek(document_file, 0, SEEK_END);
    int document_size = ftell(document_file);
    fseek(document_file, 0, SEEK_SET);

    char* document = (char*)malloc(document_size + 1);
    if (document == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        return 1;
    }

    int bytes_read = fread(document, 1, document_size, document_file);
    if (bytes_read != document_size) {
        fprintf(stderr, "Error: could not read document file\n");
        free(document);
        return 1;
    }

    document[document_size] = '\0';
    fclose(document_file);

    misspelled_word_t misspelled_words[MAX_MISSPELLED_WORDS];
    int misspelled_word_count = 0;

    check_document(dict, dict_size, document, document_size, misspelled_words, &misspelled_word_count);
    print_misspelled_words(misspelled_words, misspelled_word_count);

    free(document);
    return 0;
}

void to_lower_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

bool is_valid_character(char c) {
    return (isalpha(c) || c == '\'');
}

bool is_valid_word(dict_entry_t* dict, int dict_size, char* word) {
    // word must contain only alphabetic characters or apostrophes
    for (int i = 0; word[i]; i++) {
        if (!is_valid_character(word[i])) {
            return false;
        }
    }

    // word must not exceed maximum length
    int word_len = strlen(word);
    if (word_len > MAX_WORD_LEN) {
        return false;
    }

    // word must not be in dictionary
    int index;
    if (is_in_dictionary(dict, dict_size, word, &index)) {
        dict[index].count++;
        return false;
    }

    return true;
}

bool is_in_dictionary(dict_entry_t* dict, int dict_size, char* word, int* index) {
    to_lower_case(word);

    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            *index = i;
            return true;
        }
    }

    return false;
}

void add_to_dictionary(dict_entry_t* dict, int* dict_size, char* word) {
    if (*dict_size >= MAX_DICT_ENTRIES) {
        fprintf(stderr, "Error: maximum dictionary size exceeded\n");
        exit(1);
    }

    if (is_valid_word(dict, *dict_size, word)) {
        to_lower_case(word);
        strcpy(dict[*dict_size].word, word);
        dict[*dict_size].count = 0;
        (*dict_size)++;
    }
}

void check_document(dict_entry_t* dict, int dict_size, char* document, int document_size, misspelled_word_t* misspelled_words, int* misspelled_word_count) {
    int line = 1;
    char word[MAX_WORD_LEN + 1];
    int word_pos = 0;

    for (int i = 0; i < document_size; i++) {
        char c = document[i];

        if (c == '\n') {
            line++;
        }

        if (!is_valid_character(c)) {
            word[word_pos] = '\0';
            word_pos = 0;

            if (strlen(word) > 0 && is_valid_word(dict, dict_size, word)) {
                if (*misspelled_word_count >= MAX_MISSPELLED_WORDS) {
                    fprintf(stderr, "Error: maximum misspelled word count exceeded\n");
                    exit(1);
                }

                strcpy(misspelled_words[*misspelled_word_count].word, word);
                misspelled_words[*misspelled_word_count].line = line;
                (*misspelled_word_count)++;
            }
        } else {
            word[word_pos++] = c;
        }
    }
}

void print_misspelled_words(misspelled_word_t* misspelled_words, int misspelled_word_count) {
    printf("Misspelled words:\n");
    printf("-----------------\n");

    for (int i = 0; i < misspelled_word_count; i++) {
        printf("%s (line %d)\n", misspelled_words[i].word, misspelled_words[i].line);
    }

    printf("\n");
}