//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define DICTIONARY_SIZE 3000
#define MAX_MISSPELLED 5

// A linked list to store the misspelled words
struct misspelled_word {
    char word[MAX_WORD_LEN + 1];
    int line_number;
    struct misspelled_word *next;
};

void remove_punctuations(char *word);
void to_lowercase(char *word);
int read_line(FILE *file, char *line, int max_len);
int load_dictionary(FILE *file, char dictionary[][MAX_WORD_LEN]);
int spell_check(FILE *file, char dictionary[][MAX_WORD_LEN], struct misspelled_word **head);
void add_misspelled_word(struct misspelled_word **head, char *word, int line_number);
void free_misspelled_words(struct misspelled_word **head);
void print_misspelled_words(struct misspelled_word *head);

int main(int argc, char *argv[]) {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LEN];
    char *filename;
    FILE *file;
    int n = 0;

    struct misspelled_word *misspelled_words = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s dictionary_file text_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Failed to load dictionary file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    n = load_dictionary(file, dictionary);
    fclose(file);

    if (n == 0) {
        fprintf(stderr, "Error: Dictionary file %s is empty.\n", filename);
        exit(EXIT_FAILURE);
    }

    filename = argv[2];
    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open text file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    int misspelled_word_count = spell_check(file, dictionary, &misspelled_words);
    fclose(file);

    if (misspelled_word_count > 0) {
        print_misspelled_words(misspelled_words);
        free_misspelled_words(&misspelled_words);
        exit(EXIT_FAILURE);
    }

    printf("No spelling errors found.\n");
    return EXIT_SUCCESS;
}

int read_line(FILE *file, char *line, int max_len) {
    int ch, i = 0;

    while ((ch = fgetc(file)) != '\n' && ch != EOF) {
        if (i < max_len) {
            line[i++] = (char)ch;
        }
    }

    line[i] = '\0';
    return i;
}

int load_dictionary(FILE *file, char dictionary[][MAX_WORD_LEN]) {
    char word[MAX_WORD_LEN + 1];
    int i = 0;

    while (read_line(file, word, MAX_WORD_LEN) > 0) {
        to_lowercase(word);
        strcpy(dictionary[i++], word);
    }

    return i;
}

void to_lowercase(char *word) {
    int i = 0;

    while (word[i] != '\0') {
        word[i] = tolower((unsigned char)word[i]);
        i++;
    }
}

void remove_punctuations(char *word) {
    int i = 0;

    while (word[i] != '\0') {
        if (ispunct(word[i])) {
            memmove(&word[i], &word[i + 1], strlen(word) - i);
        } else {
            i++;
        }
    }
}

int spell_check(FILE *file, char dictionary[][MAX_WORD_LEN], struct misspelled_word **head) {
    int line_number = 0, misspelled_word_count = 0;
    char line[MAX_WORD_LEN + 1], *word;

    while (read_line(file, line, MAX_WORD_LEN) > 0) {
        line_number++;

        word = strtok(line, " ");

        while (word != NULL) {
            remove_punctuations(word);
            to_lowercase(word);

            int found = 0, i = 0;

            while (i < DICTIONARY_SIZE && dictionary[i][0] != '\0') {
                if (strcmp(word, dictionary[i]) == 0) {
                    found = 1;
                    break;
                }

                i++;
            }

            if (!found) {
                misspelled_word_count++;
                add_misspelled_word(head, word, line_number);
            }

            word = strtok(NULL, " ");

            if (misspelled_word_count > MAX_MISSPELLED) {
                return misspelled_word_count;
            }
        }
    }

    return misspelled_word_count;
}

void add_misspelled_word(struct misspelled_word **head, char *word, int line_number) {
    struct misspelled_word *current = *head;
    struct misspelled_word *new_word = malloc(sizeof(struct misspelled_word));

    if (new_word == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for misspelled word.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_word->word, word);
    new_word->line_number = line_number;
    new_word->next = NULL;

    if (*head == NULL) {
        *head = new_word;
    } else {
        struct misspelled_word *prev = NULL;

        while (current != NULL) {
            if (strcmp(word, current->word) < 0) {
                break;
            }

            prev = current;
            current = current->next;
        }

        if (prev == NULL) {
            new_word->next = *head;
            *head = new_word;
        } else {
            prev->next = new_word;
            new_word->next = current;
        }
    }
}

void free_misspelled_words(struct misspelled_word **head) {
    struct misspelled_word *current = *head;

    while (current != NULL) {
        struct misspelled_word *temp = current;

        current = current->next;
        free(temp);
    }

    *head = NULL;
}

void print_misspelled_words(struct misspelled_word *head) {
    printf("%d misspelled words found:\n\n", MAX_MISSPELLED+1);
    struct misspelled_word *current = head;
    int i = 0;

    while (current != NULL && i <= MAX_MISSPELLED) {
        printf("%s (line %d)\n", current->word, current->line_number);
        current = current->next;
        i++;
    }

    if (current != NULL) {
        printf("And %d more ...\n", MAX_MISSPELLED+1-i);
    }

    printf("\n");
}