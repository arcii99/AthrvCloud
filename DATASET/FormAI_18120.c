//FormAI DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 1000

char* remove_punctuation(char* sentence){
    int len = strlen(sentence);
    int pos = 0;

    for(int i=0; i<len; i++){
        if(isalnum(sentence[i]) || sentence[i] == ' '){
            sentence[pos++] = tolower(sentence[i]);
        }
    }

    sentence[pos] = '\0';
    return sentence;
}

int main(){
    char article[MAX_SENTENCES][MAX_SENTENCE_LEN];
    char summary[MAX_SENTENCE_LEN]; 
    
    printf("Enter article: \n");

    // Get the article
    int i = 0;
    int total_sentences = 0;
    while(i < MAX_SENTENCES && fgets(article[i], MAX_SENTENCE_LEN, stdin)){
        if(article[i][0] == '\n') break;

        total_sentences++;
        i++;
    }
    
    // Summarize the article
    for(int i=0; i<total_sentences; i++){
        // Remove punctuation and convert to lower case
        remove_punctuation(article[i]);

        // Keywords to check
        const char *keywords[] = {"important", "major", "significant", "crucial"};

        // Check if sentence contains keyword
        int contains_keyword = 0;
        for(int j=0; j<sizeof(keywords)/sizeof(keywords[0]); j++){
            if(strstr(article[i], keywords[j])){
                contains_keyword = 1;
                break;
            }
        }

        // If sentence contains keyword, add to summary
        if(contains_keyword){
            strcat(summary, article[i]);
            strcat(summary, ". ");
        }
    }
    
    printf("\nSummary: \n%s\n", summary);

    return 0;
}