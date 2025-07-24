//FormAI DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_TEXT_SIZE 10000
#define MAX_SENTENCES 500
#define MAX_SUMMARY_SIZE 500

// This function simply removes punctuation marks and replaces them with whitespace.
void remove_punctuations(char* text) {
    int text_length = strlen(text);
    for(int i=0; i<text_length; i++) {
        if(text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '!' || text[i] == '?') {
            text[i] = ' ';
        }
    }
}

int main() {
    char* input_text = (char*) malloc(sizeof(char) * MAX_INPUT_TEXT_SIZE); 
    char* sentences[MAX_SENTENCES];
    char* summary[MAX_SUMMARY_SIZE];
    int sentence_lengths[MAX_SENTENCES];
    int num_sentences = 0;
    int num_summary_sentences = 0;
    
    printf("Input the Text you want to summarize: \n");
    fgets(input_text, MAX_INPUT_TEXT_SIZE, stdin);
    remove_punctuations(input_text);
    
    char* word = strtok(input_text, " ");
    char sentence[MAX_INPUT_TEXT_SIZE];
    while(word != NULL) {
        strcat(sentence, word);
        strcat(sentence, " ");
        if(word[strlen(word)-1] == '.') {
            sentence_lengths[num_sentences] = strlen(sentence);
            sentences[num_sentences++] = strdup(sentence);
            memset(sentence, 0, sizeof(sentence));
        }
        word = strtok(NULL, " ");
    }
    
    printf("Enter the number of sentences you want in summary: ");
    int num_summary_sentences_limit;
    scanf("%d", &num_summary_sentences_limit);
    
    if(num_summary_sentences_limit > num_sentences) {
        printf("Error: You cannot summarize more sentences than available.\n");
        return 0;
    }
    
    int sentence_scores[num_sentences];
    memset(sentence_scores, 0, sizeof(sentence_scores));
    for(int i=0; i<num_sentences; i++) {
        char* word = strtok(sentences[i], " ");
        while(word != NULL) {
            for(int j=0; j<num_sentences; j++) {
                if(strstr(sentences[j], word) != NULL) {
                    sentence_scores[i]++;
                }
            }
            word = strtok(NULL, " ");
        }
    }
    
    while(num_summary_sentences < num_summary_sentences_limit) {
        int max_score_index = 0;
        for(int i=1; i<num_sentences; i++) {
            if(sentence_scores[i] > sentence_scores[max_score_index]) {
                max_score_index = i;
            }
        }
        sentence_scores[max_score_index] = -1;
        summary[num_summary_sentences++] = sentences[max_score_index];
    }
    
    printf("Summary:\n\n");
    for(int i=0; i<num_summary_sentences_limit; i++) {
        printf("%s\n", summary[i]);
    }
    
    free(input_text);
    for(int i=0; i<num_sentences; i++) {
        free(sentences[i]);
    }
    for(int i=0; i<num_summary_sentences; i++) {
        free(summary[i]);
    }
    
    return 0;
}