//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1000

void summarize(const char* input_text, char* output_text, int output_size) {
    char* text_copy = malloc(sizeof(char) * (strlen(input_text) + 1));
    strcpy(text_copy, input_text);

    char* sentence = strtok(text_copy, ".!?");

    int sentence_count = 0;
    while(sentence != NULL) {
        sentence_count++;
        sentence = strtok(NULL, ".!?");
    }

    free(text_copy);

    int sentence_num = 0;
    int max_sentence_length = output_size / sentence_count;

    char* output_copy = output_text;

    sentence = strtok(input_text, ".!?");

    while(sentence != NULL) {
        int sentence_length = strlen(sentence);
        if(sentence_length <= max_sentence_length) {
            strcpy(output_copy, sentence);
            output_copy += sentence_length;
            *output_copy = ' ';
            output_copy++;
            sentence_num++;
        }
        if(sentence_num == sentence_count) {
            break;
        }
        sentence = strtok(NULL, ".!?");
    }

    *output_copy = '\0';
}

int main() {
    char* input = "This is a sample text to be summarized. It contains multiple sentences. The purpose is to test the summarizing function. The output text should contain the most important information of the input text.";
    char* output = malloc(sizeof(char) * MAX_SIZE);

    summarize(input, output, MAX_SIZE);

    printf("%s\n", output);

    free(output);
}