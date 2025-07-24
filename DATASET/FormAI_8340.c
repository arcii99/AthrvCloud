//FormAI DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_CHARACTERS 2000

void tokenize_text(char* text, char* words[MAX_WORDS], int* num_words) {
    char* token = strtok(text, " ");
    while(token) {
        words[(*num_words)++] = token;
        token = strtok(NULL, " ");
    }
}

void print_summary(char* summary) {
    printf("Summary: %s\n", summary);
}

char* get_summary(char* text, float threshold) {
    char* words[MAX_WORDS];
    int num_words = 0;
    tokenize_text(text, words, &num_words);
    
    int freq[MAX_WORDS] = {0};
    int i, j;
    for(i = 0; i < num_words; i++) {
        for(j = 0; j < num_words; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                freq[j]++;
            }
        }
    }
    
    int max_freq = 0;
    for(i = 0; i < num_words; i++) {
        if(freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    char* summary = (char*)malloc(MAX_CHARACTERS * sizeof(char));
    int summary_len = 0;
    for(i = 0; i < num_words; i++) {
        if((float)freq[i] / max_freq >= threshold) {
            int word_len = strlen(words[i]);
            if(summary_len + word_len >= MAX_CHARACTERS - 1) {
                break;
            }
            
            if(summary_len > 0) {
                summary[summary_len++] = ' ';
            }
            
            strcpy(&summary[summary_len], words[i]);
            summary_len += word_len;
        }
    }
    
    summary[summary_len] = '\0';
    return summary;
}

int main() {
    char text[] = "This is a sample text. It contains multiple sentences and words. The purpose of this text is to provide an example of how the summarizer works.";
    char* summary = get_summary(text, 0.5);
    print_summary(summary);
    free(summary);
    return 0;
}