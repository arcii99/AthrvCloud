//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SENTENCE_LEN 1000
#define MAX_SUMMARY_LEN 500

void summarize(char[]);

int main(){
    char article[MAX_SUMMARY_LEN];
    printf("Enter the article to be summarized: ");
    fgets(article, MAX_SUMMARY_LEN, stdin);
    printf("\nSummarized article:\n");
    summarize(article);
    return 0;
}

void summarize(char article[]){
    int i, j, count = 0;
    char summary[MAX_SUMMARY_LEN] = "";
    char sentence[MAX_SENTENCE_LEN] = "";
    char *token, *last_token;
    const char delim[] = ".!?";

    // Split the article into sentences
    for(i=0; i < strlen(article); i++){
        sentence[count++] = article[i];
        for(j=0; j<strlen(delim); j++){
            if(article[i] == delim[j]){
                if(count > 1){
                    sentence[count-1] = '\0';
                    token = strtok_r(sentence, " ", &last_token);
                    int num_tokens = 0;
                    // Count the number of tokens in the sentence
                    while (token != NULL) {
                        num_tokens++;
                        token = strtok_r(NULL, " ", &last_token);
                    }
                    // If sentence has more than 4 tokens, add it to the summary
                    if(num_tokens >= 4){
                        strcat(summary, sentence);
                        strcat(summary, delim+j);
                    }
                }
                count = 0;
                break;
            }
        }
    }
    printf("%s", summary);
}