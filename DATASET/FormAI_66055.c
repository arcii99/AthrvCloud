//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This function removes any non-alphabetic characters from a string
void remove_non_alpha(char *str) {
    int i = 0, j = 0;
    while (str[j]) {
        if (isalpha(str[j]))
            str[i++] = tolower(str[j]);
        j++;
    }
    str[i] = '\0';
}

// This function adds a word to the list of unique words or increments its frequency
void add_word(char *word, char **unique_words, int *word_count) {
    int i;
    for (i = 0; i < *word_count; i++) {
        if (strcmp(word, unique_words[i]) == 0) {
            // this word is already in the list
            return;
        }
    }

    // Not found, so add it to the list
    unique_words[*word_count] = strdup(word);
    (*word_count)++;
}

// This function reads words from a file and adds them to our list (if we haven't seen them before)
void read_file(char *filename, char **unique_words, int *word_count) {
    FILE *fp = fopen(filename, "r");
    char buf[1024];
    while (fscanf(fp, "%1023s", buf) == 1) { // scanf with a max width prevents buffer overflows
        remove_non_alpha(buf);
        if (strlen(buf) > 0) { // skip empty strings
            add_word(buf, unique_words, word_count);
        }
    }
    fclose(fp);
}

// This function prints out each unique word and its frequency
void print_word_count(char **unique_words, int *word_frequency, int word_count) {
    int i;
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", unique_words[i], word_frequency[i]);
    }
}

// This is the main program, which reads the file and prints the word frequency count
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *unique_words[10000]; // our list of unique words
    int word_frequency[10000] = { 0 }; // array to hold the frequency of each unique word
    int word_count = 0; // the number of unique words we've seen so far

    read_file(filename, unique_words, &word_count);

    // count the frequency of each word
    FILE *fp = fopen(filename, "r");
    char buf[1024];
    while (fscanf(fp, "%1023s", buf) == 1) {
        remove_non_alpha(buf);
        if (strlen(buf) > 0) {
            int i;
            for (i = 0; i < word_count; i++) {
                if (strcmp(buf, unique_words[i]) == 0) {
                    word_frequency[i]++;
                    break;
                }
            }
        }
    }
    fclose(fp);

    print_word_count(unique_words, word_frequency, word_count);

    return 0;
}