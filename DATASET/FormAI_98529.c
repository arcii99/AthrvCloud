//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SENTENCE_LENGTH 1000

char* summarize(char* input){
    char *output = (char*)calloc(MAX_SENTENCE_LENGTH*MAX_SENTENCES, sizeof(char));
    char *sentences[MAX_SENTENCES];
    int sentence_count = 0;
    int i, j;
    
    sentences[0] = strtok(input, ".!?");
    sentence_count = 1;
    
    while((sentences[sentence_count] = strtok(NULL, ".!?")) != NULL){
        sentence_count++;
    }
    
    int sentence_scores[sentence_count];
    
    for(i=0; i<sentence_count; i++){
        sentence_scores[i] = 0;
        char *words = strtok(sentences[i], " ");
        while(words != NULL){
            int length = strlen(words);
            if(length > 6){
                sentence_scores[i]++;
            }
            words = strtok(NULL, " ");
        }
    }
    
    int max_sentence_score = 0;
    for(i=0; i<sentence_count; i++){
        if(sentence_scores[i] > max_sentence_score){
            max_sentence_score = sentence_scores[i];
        }
    }
    
    for(i=0; i<sentence_count; i++){
        if(sentence_scores[i] == max_sentence_score){
            strcat(output, sentences[i]);
            strcat(output, ". ");
        }
    }
    
    return output;
}

int main(){
    char text[10000];
    printf("Enter text to be summarized:\n");
    fgets(text, 10000, stdin);
    char *output = summarize(text);
    printf("\nSummarized Text:\n%s", output);
    free(output);
    return 0;
}