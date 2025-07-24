//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 500
#define MAX_WORDS 50

typedef struct {
    char *start;
    char *end;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    size_t size;
} WordArray;

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void drop_spaces(char **text) {
    while(is_whitespace(**text)) {
        (*text)++;
    }
}

int parse_word(char **text, Word *word) {
    word->start = *text;
    while(!is_whitespace(**text) && **text) {
        (*text)++;
    }
    word->end = *text;
    drop_spaces(text);
    return word->end - word->start;
}

void parse_word_array(char *text, WordArray *array) {
    array->size = 0;
    while(*text && array->size < MAX_WORDS) {
        parse_word(&text, &array->words[array->size++]);
    }
    array->words[array->size].start = NULL;
    array->words[array->size].end = NULL;
}

int has_word(WordArray *array, char *word) {
    for(int i = 0; i < array->size; ++i) {
        if(!strncmp(array->words[i].start, word, array->words[i].end - array->words[i].start)) {
            return 1;
        }
    }
    return 0;
}

int parse_resume(char *text) {
    WordArray words;
    parse_word_array(text, &words);
    int score = 0;
    if(has_word(&words, "C")) {
        score++;
    }
    if(has_word(&words, "Resume")) {
        score++;
    }
    if(has_word(&words, "Parsing")) {
        score++;
    }
    if(has_word(&words, "System")) {
        score++;
    }
    return score;
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter your resume:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    int score = parse_resume(buffer);
    printf("Your resume has a score of %d out of 4\n", score);
    return 0;
}