//FormAI DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 50
#define MAX_LINES 1000
#define MAX_WORDS 10000

typedef struct {
    char word[WORD_SIZE];
    int frequency;
} Word;

int read_file(char *filename, char *lines[MAX_LINES]);
void clean_lines(char *lines[MAX_LINES], int count);
int process_lines(char *lines[MAX_LINES], int count, Word words[MAX_WORDS]);
void sort_words(Word words[MAX_WORDS], int count);
void display_results(Word words[MAX_WORDS], int count);

int main() {
    char *lines[MAX_LINES];
    Word words[MAX_WORDS];
    int num_lines, num_words;

    num_lines = read_file("input.txt", lines);
    clean_lines(lines, num_lines);
    num_words = process_lines(lines, num_lines, words);
    sort_words(words, num_words);
    display_results(words, num_words);

    return 0;
}

int read_file(char *filename, char *lines[MAX_LINES]) {
    FILE *file;
    char buffer[WORD_SIZE];
    int count = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buffer, WORD_SIZE, file) != NULL) {
        if (count == MAX_LINES) {
            printf("Too many lines.\n");
            exit(1);
        }

        lines[count] = malloc(strlen(buffer));
        strcpy(lines[count], buffer);
        count++;
    }

    fclose(file);
    return count;
}

void clean_lines(char *lines[MAX_LINES], int count) {
    int i;

    for (i = 0; i < count; i++) {
        if (strlen(lines[i]) > 0 && lines[i][strlen(lines[i]) - 1] == '\n') {
            lines[i][strlen(lines[i]) - 1] = '\0';
        }
    }
}

int process_lines(char *lines[MAX_LINES], int count, Word words[MAX_WORDS]) {
    char *token;
    char delims[] = " ,.!?\"();\n";
    int i, j, word_count = 0;

    for (i = 0; i < count; i++) {
        token = strtok(lines[i], delims);
        while (token != NULL) {
            for (j = 0; j < word_count; j++) {
                if (strcmp(words[j].word, token) == 0) {
                    words[j].frequency++;
                    break;
                }
            }

            if (j == word_count) {
                if (word_count == MAX_WORDS) {
                    printf("Too many words.\n");
                    exit(1);
                }

                strcpy(words[word_count].word, token);
                words[word_count].frequency = 1;
                word_count++;
            }

            token = strtok(NULL, delims);
        }
    }

    return word_count;
}

void sort_words(Word words[MAX_WORDS], int count) {
    Word temp;
    int i, j;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (words[j].frequency < words[j+1].frequency) {
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

void display_results(Word words[MAX_WORDS], int count) {
    int i;

    printf("Word\tFrequency\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}