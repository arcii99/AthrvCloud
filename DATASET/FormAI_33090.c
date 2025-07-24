//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

// Function to remove punctuation and convert all characters to lowercase
char* clean_word(char *word) {
    int i;
    char *cleaned_word = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    for(i = 0; i < strlen(word); i++) {
        if(ispunct(word[i])) {
            continue;    // skip punctuation
        }
        cleaned_word[i] = tolower(word[i]);    // convert to lowercase
    }
    cleaned_word[i] = '\0';    // add null terminator
    return cleaned_word;
}

// Function to increment word count in the hash table
void increment_word_count(char *word, int *word_count, int hash_size) {
    int hash = 0;
    for(int i = 0; word[i] != '\0'; i++) {
        hash = (hash << 3) + word[i];    // calculate hash value for word
    }
    hash = hash % hash_size;    // reduce hash value to fit into array size
    word_count[hash]++;    // increment count for corresponding hash value
}

// Function to print frequency count of each word in the hash table
void print_word_count(int *word_count, int hash_size) {
    printf("Word frequency count:\n");
    for(int i = 0; i < hash_size; i++) {
        if(word_count[i] > 0) {    // print only if word count is greater than zero
            printf("%d occurrences of word %d\n", word_count[i], i);
        }
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");    // open input file for reading
    if(file == NULL) {
        printf("Error: Unable to open input file\n");
        return 1;
    }

    int hash_size = 10000;    // size of the hash table
    int *word_count = (int*)calloc(hash_size, sizeof(int));    // initialize hash table with all zeroes

    char line[MAX_LINE_LENGTH], *word, *cleaned_word;
    while(fgets(line, MAX_LINE_LENGTH, file)) {   // read input file line by line
        word = strtok(line, " ");    // tokenize line by space
        while(word != NULL) {
            cleaned_word = clean_word(word);    // clean word
            increment_word_count(cleaned_word, word_count, hash_size);    // increment word count in hash table
            free(cleaned_word);    // free memory allocated to cleaned word
            word = strtok(NULL, " ");    // get next word
        }
    }

    fclose(file);    // close input file

    print_word_count(word_count, hash_size);    // print word frequency count

    free(word_count);    // free memory allocated to hash table

    return 0;
}