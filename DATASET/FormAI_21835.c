//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_UNIQUE_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_freq;

int is_word(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void add_word(word_freq* word_freq_array, char* word, int* unique_word_count, int* total_word_count) {
    for(int i = 0; i < *unique_word_count; i++) {
        if(strcmp(word, word_freq_array[i].word) == 0) {
            word_freq_array[i].frequency++;
            (*total_word_count)++;
            return;
        }
    }

    // word does not exist in word_freq_array
    word_freq wf;
    strcpy(wf.word, word);
    wf.frequency = 1;
    word_freq_array[*unique_word_count] = wf;
    (*unique_word_count)++;
    (*total_word_count)++;
}

int compare_word_freq(const void* a, const void* b) {
    word_freq* wf1 = (word_freq*)a;
    word_freq* wf2 = (word_freq*)b;

    if(wf1->frequency != wf2->frequency) {
        return wf2->frequency - wf1->frequency; // sort by descending order of frequency
    }

    return strcmp(wf1->word, wf2->word); // sort by ascending order of word alphabetical order
}

void print_word_stats(word_freq* word_freq_array, int unique_word_count, int total_word_count, int top_n) {
    qsort(word_freq_array, unique_word_count, sizeof(word_freq), compare_word_freq);

    printf("Total words: %d\n", total_word_count);
    printf("Unique words: %d\n\n", unique_word_count);

    printf("Top %d most frequent words:\n", top_n);
    for(int i = 0; i < top_n && i < unique_word_count; i++) {
        printf("%s (%d)\n", word_freq_array[i].word, word_freq_array[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s FILENAME\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Failed to open file %s\n", argv[1]);
        return 1;
    }

    char c;
    char word[MAX_WORD_LENGTH];
    int unique_word_count = 0;
    int total_word_count = 0;
    word_freq word_freq_array[MAX_UNIQUE_WORDS];

    while((c = fgetc(fp)) != EOF) {
        if(is_word(c)) {
            strncat(word, &c, 1);
        } else {
            if(word[0] != '\0') {
                add_word(word_freq_array, word, &unique_word_count, &total_word_count);
                word[0] = '\0'; // reset word
            }
        }
    }

    // catch the last word in the file, if exists
    if(word[0] != '\0') {
        add_word(word_freq_array, word, &unique_word_count, &total_word_count);
    }

    fclose(fp);

    print_word_stats(word_freq_array, unique_word_count, total_word_count, 10); // print top 10 most frequent words

    return 0;
}