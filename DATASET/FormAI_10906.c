//FormAI DATASET v1.0 Category: Text Summarizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// Function to convert the string to lowercase
void toLower(char *s) {
    while (*s) {
        *s = tolower(*s);
        s++;
    }
}

// Function to tokenize the input sentence
int tokenize(char *input, char tokens[][MAX_WORD_LENGTH]) {
    int tokenCount = 0;
    char *token = strtok(input, " \n");

    while (token != NULL) {
        strcpy(tokens[tokenCount], token);
        toLower(tokens[tokenCount]); // Convert to lowercase
        token = strtok(NULL, " \n");
        tokenCount++;
    }

    return tokenCount;
}

// Function to check if a word is a stop word
int isStopWord(char *word) {
    static char *stopWords[] = {"a", "an", "the", "in", "on", "at", "to", "from", "by", "with"};
    int numStopWords = sizeof(stopWords) / sizeof(char *);
    int i;

    for (i = 0; i < numStopWords; i++) {
        if (strcmp(stopWords[i], word) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to count the number of non-stop words in a sentence
int countWords(char tokens[][MAX_WORD_LENGTH], int numTokens) {
    int count = 0;
    int i;

    for (i = 0; i < numTokens; i++) {
        if (!isStopWord(tokens[i])) {
            count++;
        }
    }

    return count;
}

// Structure to hold sentences and their scores
typedef struct Sentence {
    char text[MAX_WORD_LENGTH * 20];
    double score;
} Sentence;

// Compare function for sorting sentences by score
int compare(const void *a, const void *b) {
    Sentence *s1 = (Sentence *)a;
    Sentence *s2 = (Sentence *)b;

    if (s1->score < s2->score) {
        return 1;
    } else if (s1->score > s2->score) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    char input[1000];
    char tokens[100][MAX_WORD_LENGTH];
    Sentence sentences[10];
    int numSentences = 0;
    int numTokens = 0;
    int i, j;

    // Take input from user
    printf("Enter the text to be summarized:\n");
    fgets(input, 1000, stdin);

    // Tokenize the input
    numTokens = tokenize(input, tokens);

    // Create sentences
    for (i = 0; i < numTokens; i++) {
        if (tokens[i][strlen(tokens[i]) - 1] == '.' || tokens[i][strlen(tokens[i]) - 1] == '?' || tokens[i][strlen(tokens[i]) - 1] == '!') {
            // End of sentence detected
            strncpy(sentences[numSentences].text, tokens[i - countWords(tokens, i) + 1], strlen(tokens[i - countWords(tokens, i) + 1]));
            for (j = i - countWords(tokens, i) + 2; j <= i; j++) {
                strcat(sentences[numSentences].text, " ");
                strcat(sentences[numSentences].text, tokens[j]);
            }
            sentences[numSentences].score = (double)countWords(tokens, i) / (double)(i - countWords(tokens, i) + 1);
            numSentences++;
        }
    }

    // Sort sentences by score
    qsort(sentences, numSentences, sizeof(Sentence), compare);

    // Print summary
    printf("Summary:\n");
    for (i = 0; i < numSentences / 2; i++) {
        printf("%s.\n", sentences[i].text);
    }

    return 0;
}