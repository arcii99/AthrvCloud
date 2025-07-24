//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX_LEN 50

int count_words(char* text);

int main() {
    char* text = "The quick brown fox jumps over the lazy dog.";
    int word_count = count_words(text);
    printf("Word count: %d", word_count);
    return 0;
}

int count_words(char* text) {
    int count = 0;
    char* ptr = strtok(text, " "); // Split text by spaces
    
    while (ptr != NULL) {
        if (strlen(ptr) <= WORD_MAX_LEN) {
            count++;
        }
        ptr = strtok(NULL, " "); // Get next word
    }
    
    return count;
}