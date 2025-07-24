//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct word_count {
    char* word;
    int count;
} word_count;

int is_valid_word_char(char c) {
    return isalpha(c) || c == '\'';
}

void increment_count(word_count* wc_array, char* word) {
    int i = 0;
    while(wc_array[i].word != NULL) {
        if(strcmp(wc_array[i].word, word) == 0) {
            wc_array[i].count++;
            return;
        }
        i++;
    }

    wc_array[i].word = word;
    wc_array[i].count = 1;
}

int main() {
    char c;
    char word_buffer[MAX_WORD_LENGTH];
    int buffer_pos = 0;
    word_count qc[MAX_WORD_LENGTH];
    memset(qc, 0, sizeof(qc));

    while((c = getchar()) != EOF) {
        if(is_valid_word_char(c)) {
            word_buffer[buffer_pos++] = tolower(c);
            if(buffer_pos == MAX_WORD_LENGTH) {
                buffer_pos--;
            }
        } else if(buffer_pos > 0) {
            word_buffer[buffer_pos] = '\0';
            increment_count(qc, strdup(word_buffer)); // Memory Allocation
            buffer_pos = 0;
        }
    }

    printf("Word Frequency Count:\n");
    for(int i = 0; qc[i].word != NULL; i++) {
        printf("\t%s - %d\n", qc[i].word, qc[i].count);
        free(qc[i].word);  // Deallocate Memory
    }

    return 0;
}