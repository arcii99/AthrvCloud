//FormAI DATASET v1.0 Category: Text Summarizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCES 50
#define MAX_SUMMARY_LENGTH 100

int main(int argc, char *argv[]) {

    char full_text[2000];
    printf("Enter the full text:\n");
    fgets(full_text, 2000, stdin);

    char sentence_array[MAX_SENTENCES][100];
    int sentence_count = 0;

    int text_length = strlen(full_text);
    for(int i = 0; i < text_length; i++) {
        char current_char = full_text[i];
        if(current_char == '.') {
            sentence_count++;
        }
        sentence_array[sentence_count][i % 100] = current_char;
    }

    bool summary_array[MAX_SENTENCES] = {false};

    int summary_length = 0;
    int current_sentence = 0;
    while(summary_length < MAX_SUMMARY_LENGTH && current_sentence < sentence_count) {
        if(!summary_array[current_sentence]) {
            summary_array[current_sentence] = true;
            summary_length += strlen(sentence_array[current_sentence]);
        }
        current_sentence++;
    }

    printf("\n\nThe summarized text:\n");
    for(int i = 0; i < sentence_count; i++) {
        if(summary_array[i]) {
            printf("%s ", sentence_array[i]);
        }
    }
    printf("\n");

    return 0;
}