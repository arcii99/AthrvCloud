//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

struct WordFreq {
    char word[MAX_LEN];
    int freq;
};

void to_lower(char *word) {
    for(int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

void remove_punct(char *word) {
    int len = strlen(word);
    for(int i = 0; i < len; i++) {
        if(ispunct(word[i])) {
            for(int j = i; j < len - 1; j++) {
                word[j] = word[j+1];
            }
            word[len-1] = '\0';
            len--;
            i--;
        }
    }
}

int is_word(struct WordFreq *word_freq, int count, char *word) {
    for(int i = 0; i < count; i++) {
        if(strcmp(word_freq[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char text[MAX_WORDS * MAX_LEN];
    char *word;
    struct WordFreq word_freq[MAX_WORDS];
    int count = 0;
    
    printf("Enter text (max %d words):\n", MAX_WORDS);
    fgets(text, sizeof(text), stdin);
    
    word = strtok(text, " ");
    while(word != NULL && count < MAX_WORDS) {
        to_lower(word);
        remove_punct(word);
        int index = is_word(word_freq, count, word);
        if(index >= 0) {
            word_freq[index].freq++;
        } else {
            strcpy(word_freq[count].word, word);
            word_freq[count].freq = 1;
            count++;
        }
        word = strtok(NULL, " ");
    }
    
    // Sort the array by frequency
    for(int i = 1; i < count; i++) {
        for(int j = 0; j < count - i; j++) {
            if(word_freq[j].freq < word_freq[j+1].freq) {
                struct WordFreq temp = word_freq[j];
                word_freq[j] = word_freq[j+1];
                word_freq[j+1] = temp;
            }
        }
    }
    
    printf("\nWord Frequency Count:\n");
    for(int i = 0; i < count; i++) {
        printf("%s: %d\n", word_freq[i].word, word_freq[i].freq);
    }
    
    return 0;
}