//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//maximum number of sentences that can be in the summary
#define MAX_SENTENCES 10

//minimum length of a sentence to be considered for summary
#define MIN_SENTENCE_LEN 10

//maximum length of a summary sentence
#define MAX_SUMMARY_LEN 50

void summarize_text(char* text, char* summary);

int main()
{
    char text[1000];
    char summary[MAX_SUMMARY_LEN*MAX_SENTENCES];
    
    printf("Enter the text to be summarized:\n");
    fgets(text, 1000, stdin);
    
    summarize_text(text, summary);
    
    printf("Summary:\n");
    printf("%s\n", summary);
    
    return 0;
}

void summarize_text(char* text, char* summary){
    
    char sentences[MAX_SENTENCES][MAX_SUMMARY_LEN];
    char* sentence;
    int sentence_count = 0, i, j, len;
    
    //tokenize the text into sentences and store in sentences array
    sentence = strtok(text, ".!?");
    while(sentence != NULL && sentence_count < MAX_SENTENCES){
        len = strlen(sentence);
        if(len >= MIN_SENTENCE_LEN){
            sentences[sentence_count][0] = '\0';
            strncat(sentences[sentence_count], sentence, MAX_SUMMARY_LEN-1);
            sentence_count++;
        }
        sentence = strtok(NULL, ".!?");
    }
    
    //combine the first sentence with the next two sentences if they fit within MAX_SUMMARY_LEN
    for(i=0; i< sentence_count; i++){
        
        len = strlen(sentences[i]);
        
        //if the sentence has less than MAX_SUMMARY_LEN characters, add it to the summary as it is
        if(len <= MAX_SUMMARY_LEN){
            strncat(summary, sentences[i], MAX_SUMMARY_LEN-strlen(summary)-1);
            strncat(summary, ". ", MAX_SUMMARY_LEN-strlen(summary)-1);
        }
        //if the sentence has more than MAX_SUMMARY_LEN characters, try to fit the next two sentences also within MAX_SUMMARY_LEN
        else{
            for(j=i+1; j<=i+2 && j<sentence_count; j++){
                if((len + strlen(sentences[j]) + 2) <= MAX_SUMMARY_LEN){
                    strcat(sentences[i], " ");
                    strncat(sentences[i], sentences[j], MAX_SUMMARY_LEN-strlen(sentences[i])-1);
                    len = strlen(sentences[i]);
                }
                else{
                    break;
                }
            }
            strncat(summary, sentences[i], MAX_SUMMARY_LEN-strlen(summary)-1);
            strncat(summary, ". ", MAX_SUMMARY_LEN-strlen(summary)-1);
        }
    }
}