//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_CHARS_PER_LINE 200
#define MAX_SUMMARY_CHARS 500

typedef struct sentence{
    int sentence_index;
    char sentence_text[MAX_CHARS_PER_LINE];
    int sentence_score;
} sentence_t;

int count_sentences(char *text);
void tokenize_text(char *text, char token_array[MAX_LINES][MAX_CHARS_PER_LINE]);
int calculate_sentence_scores(sentence_t *sentence_array, char token_array[MAX_LINES][MAX_CHARS_PER_LINE], int num_sentences);
void sort_sentences_by_score(sentence_t *sentence_array, int num_sentences);
void generate_summary(char *summary_text, sentence_t *sentence_array, int num_sentences);

int main(){
    char original_text[MAX_LINES * MAX_CHARS_PER_LINE];
    char summary_text[MAX_SUMMARY_CHARS];
    char token_array[MAX_LINES][MAX_CHARS_PER_LINE];
    
    printf("Please enter the original text:\n");
    fgets(original_text, MAX_LINES * MAX_CHARS_PER_LINE, stdin);
    
    int num_sentences = count_sentences(original_text);
    sentence_t sentence_array[num_sentences];
    
    tokenize_text(original_text, token_array);
    int highest_score = calculate_sentence_scores(sentence_array, token_array, num_sentences);
    sort_sentences_by_score(sentence_array, num_sentences);
    generate_summary(summary_text, sentence_array, num_sentences);
    
    printf("Original text:\n%s\n",original_text);
    printf("Summary:\n%s\n",summary_text);
    
    return 0;
}

int count_sentences(char *text){
    int num_sentences = 0;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            num_sentences++;
        }
    }
    return num_sentences;
}

void tokenize_text(char *text, char token_array[MAX_LINES][MAX_CHARS_PER_LINE]){
    char *token = strtok(text, "\n");
    int i = 0;
    while(token != NULL){
        strcpy(token_array[i], token);
        token = strtok(NULL, "\n");
        i++;
    }
}

int calculate_sentence_scores(sentence_t *sentence_array, char token_array[MAX_LINES][MAX_CHARS_PER_LINE], int num_sentences){
    int highest_score = -1;
    for(int i = 0; i < num_sentences; i++){
        int sentence_score = 0;
        char *token = strtok(token_array[i], " ");
        while(token != NULL){
            int token_length = strlen(token);
            if(token_length > 6){
                sentence_score++;
            }
            token = strtok(NULL, " ");
        }
        sentence_array[i].sentence_index = i;
        strcpy(sentence_array[i].sentence_text, token_array[i]);
        sentence_array[i].sentence_score = sentence_score;
        if(sentence_score > highest_score){
            highest_score = sentence_score;
        }
    }
    return highest_score;
}

void sort_sentences_by_score(sentence_t *sentence_array, int num_sentences){
    for(int i = 0; i < num_sentences - 1; i++){
        for(int j = i + 1; j < num_sentences; j++){
            if(sentence_array[i].sentence_score < sentence_array[j].sentence_score){
                sentence_t temp_sentence = sentence_array[i];
                sentence_array[i] = sentence_array[j];
                sentence_array[j] = temp_sentence;
            }
        }
    }
}

void generate_summary(char *summary_text, sentence_t *sentence_array, int num_sentences){
    int summary_length = 0;
    for(int i = 0; i < num_sentences && summary_length < MAX_SUMMARY_CHARS; i++){
        strcat(summary_text, sentence_array[i].sentence_text);
        summary_length += strlen(sentence_array[i].sentence_text);
        strcat(summary_text, ". ");
        summary_length += 2;
    }
}