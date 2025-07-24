//FormAI DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include<stdio.h>
#include<string.h>
#define MAX_SENTENCES 20
#define MAX_WORDS 1000

int main() {

    printf("Welcome to my Text Summarizer Program! Please enter the text you want to summarize:\n");

    // Initializing variables
    char text[MAX_WORDS];
    char sentences[MAX_SENTENCES][MAX_WORDS];
    char *ptr;
    int sentence_count = 0;

    // Reading input text and converting it to sentences
    fgets(text, sizeof(text), stdin);
    ptr = strtok(text, ".");
    while(ptr!=NULL) {
        strcpy(sentences[sentence_count++], ptr);
        ptr = strtok(NULL, ".");
    }

    // Finding the most frequent words
    char words[MAX_WORDS][MAX_WORDS];
    int frequency[MAX_WORDS], index = 0, max_frequency = -1;
    ptr = strtok(text, " ,.-\n");
    while(ptr!=NULL) {
        int flag = 0;
        for(int i=0; i<index; i++) {
            if(strcmp(words[i], ptr)==0) {
                frequency[i]++;
                flag = 1;
                max_frequency = frequency[i]>max_frequency ? frequency[i] : max_frequency;
                break;
            }
        }
        if(!flag) {
            strcpy(words[index], ptr);
            frequency[index++] = 1;
        }
        ptr = strtok(NULL, " ,.-\n");
    }

    // Summarizing the text
    printf("The summarized text is:\n");
    for(int i=0; i<MAX_SENTENCES; i++) {
        int words_count = 0;
        int sentence_length = strlen(sentences[i]);
        ptr = strtok(sentences[i], " ,.-\n");
        while(ptr!=NULL) {
            for(int j=0; j<index; j++) {
                if(strcmp(words[j], ptr)==0) {
                    words_count++;
                    break;
                }
            }
            ptr = strtok(NULL, " ,.-\n");
        }
        int score = (words_count/max_frequency)*sentence_length;
        if(score>100) {
            printf("%s", sentences[i]);
        }
    }

    return 0;
}