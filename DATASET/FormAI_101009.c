//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 500

int countWords(char *sentence);
void summarize(char *text);

int main() {
    char text[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int numSentences = 0;

    printf("Enter text to be summarized (max %d sentences): \n", MAX_SENTENCES);
    while(numSentences < MAX_SENTENCES) {
        fgets(text[numSentences], MAX_SENTENCE_LENGTH, stdin);
        if(strlen(text[numSentences]) == 1 && text[numSentences][0] == '\n') break;
        numSentences++;
    }

    summarize((char *) text);
    return 0;
}

void summarize(char *text) {
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int wordCount[MAX_SENTENCES];
    char summary[MAX_SUMMARY_LENGTH] = "";
    int sentenceCount = 0;

    // Split text into sentences and count word in each sentence
    for(char *sentence = strtok(text, ".\n"); sentence != NULL; sentence = strtok(NULL, ".\n")) {
        strcpy(sentences[sentenceCount], sentence);
        wordCount[sentenceCount] = countWords(sentence);
        sentenceCount++;
    }

    // Sort sentences by word count (descending order)
    for(int i = 0; i < sentenceCount; i++) {
        for(int j = i+1; j < sentenceCount; j++) {
            if(wordCount[j] > wordCount[i]) {
                int tempCount = wordCount[i];
                wordCount[i] = wordCount[j];
                wordCount[j] = tempCount;
                char tempSentence[MAX_SENTENCE_LENGTH];
                strcpy(tempSentence, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], tempSentence);
            }
        }
    }

    // Add top 3 sentences to summary
    int addedSentences = 0;
    for(int i = 0; i < sentenceCount && addedSentences < 3; i++) {
        if(wordCount[i] > 0) {
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
            addedSentences++;
        }
    }

    printf("Summary: %s\n", summary);
}

int countWords(char *sentence) {
    int wordCount = 0;

    // Skip leading whitespaces
    while(isspace(*sentence)) sentence++;

    // Count words in sentence
    while(*sentence) {
        if(!isspace(*sentence) && (isspace(*(sentence+1)) || *(sentence+1) == '\0'))
            wordCount++;
        sentence++;
    }

    return wordCount;
}