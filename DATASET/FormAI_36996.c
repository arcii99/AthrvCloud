//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_INPUT_SIZE 200
#define MAX_OUTPUT_SIZE 50

// Defining a structure to store sentences and their corresponding scores
struct Sentence {
    char value[MAX_INPUT_SIZE];
    int score;
};

// Defining a function to calculate the score of a sentence based on the frequency of its words in the input text
int sentenceScore(char *sentence, char *keywords[], int keywordCount) {
    int score = 0;
    char* word = strtok(sentence, " ");
    while(word != NULL) {
        for(int i=0; i<keywordCount; i++) {
            if(strcmp(word, keywords[i]) == 0) {
                score++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char inputText[MAX_INPUT_SIZE];
    printf("Enter the text to be summarized (maximum 200 characters):\n");
    fgets(inputText, MAX_INPUT_SIZE, stdin);
    char* keywords[] = {"visionary", "unique", "program", "code", "compile", "run", "error", "text", "summarizer"};

    // Creating an array of sentences
    char* sentence[MAX_OUTPUT_SIZE];
    sentence[0] = strtok(inputText, ".\n");
    int sentenceCount = 0;
    while (sentence[sentenceCount] != NULL) {
        sentenceCount++;
        sentence[sentenceCount] = strtok(NULL, ".\n");
    }

    // Creating an array of Sentence structures to store each sentence and its score
    struct Sentence sentences[sentenceCount];
    for(int i=0; i<sentenceCount; i++) {
        strcpy(sentences[i].value, sentence[i]);
        sentences[i].score = sentenceScore(sentences[i].value, keywords, sizeof(keywords)/sizeof(char*));
    }

    // Sorting the array of sentences based on their scores
    for(int i=0; i<sentenceCount-1; i++) {
        for(int j=i+1; j<sentenceCount; j++) {
            if(sentences[i].score < sentences[j].score) {
                struct Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    // Printing the top 3 sentences with the highest scores
    printf("\nTOP 3 SENTENCES:\n");
    for(int i=0; i<3; i++) {
        printf("%d. %s\n", i+1, sentences[i].value);
    }

    return 0;
}