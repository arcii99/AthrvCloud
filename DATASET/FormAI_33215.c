//FormAI DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 1000
#define MAX_SENTENCES 100

int countWords(char*);
int countSentences(char*);
void tokenize(char*);
void summarize(char*);

char text[MAX_STR_LENGTH];
char sentences[MAX_SENTENCES][MAX_STR_LENGTH];
char words[MAX_SENTENCES][MAX_STR_LENGTH][MAX_STR_LENGTH];

int main() {
    printf("Enter text to be summarized: ");
    fgets(text, MAX_STR_LENGTH, stdin);

    tokenize(text);
    summarize(text);

    return 0;
}

int countWords(char* sentence) {
    int count = 0;
    char* token = strtok(sentence, " ");
    
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    
    return count;
}

int countSentences(char* text) {
    int count = 0;
    int len = strlen(text);
    
    for (int i = 0; i < len; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            count++;
        }
    }
    
    return count;
}

void tokenize(char* text) {
    char* sentence = strtok(text, ".?!");

    int i = 0;
    while (sentence != NULL) {
        strcpy(sentences[i], sentence);
        char* word = strtok(sentence, " ");

        int j = 0;
        while (word != NULL) {
            strcpy(words[i][j], word);
            j++;
            word = strtok(NULL, " ");
        }

        i++;
        sentence = strtok(NULL, ".?!");
    }
}

void summarize(char* text) {
    int numSentences = countSentences(text);
    int sentenceLen[numSentences];
    int sentenceScore[numSentences];

    // Calculate score for each sentence
    for (int i = 0; i < numSentences; i++) {
        sentenceLen[i] = strlen(sentences[i]);
        sentenceScore[i] = countWords(sentences[i]);
    }

    // sort sentences in descending order based on score

    for (int i = 0; i < numSentences - 1; i++) {
        for (int j = i + 1; j < numSentences; j++) {
            if (sentenceScore[i] < sentenceScore[j]) {
                // swap scores
                int tempScore = sentenceScore[i];
                sentenceScore[i] = sentenceScore[j];
                sentenceScore[j] = tempScore;

                // swap sentence lengths
                int tempLen = sentenceLen[i];
                sentenceLen[i] = sentenceLen[j];
                sentenceLen[j] = tempLen;

                // swap sentences
                char temp[MAX_STR_LENGTH];
                strcpy(temp, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], temp);
            }
        }
    }

    // Calculate summary length
    int summaryLen = 0;
    for (int i = 0; i < numSentences; i++) {
        summaryLen += sentenceLen[i];
        if (summaryLen > MAX_STR_LENGTH) {
            break;
        }
    }

    // Output summary
    printf("Summary:\n");
    for (int i = 0; i < numSentences; i++) {
        summaryLen += sentenceLen[i];
        printf("%s", sentences[i]);
        if (summaryLen > MAX_STR_LENGTH) {
            break;
        }
    }
}