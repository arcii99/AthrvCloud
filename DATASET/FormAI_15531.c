//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1000
#define MAX_SENTENCES 100

void printSummary(char *inputText, int numSentences) {
    int sentenceCount = 0;
    char *sentences[MAX_SENTENCES];
    char *tok = strtok(inputText, ".");
    while (tok != NULL && sentenceCount < numSentences) {
        sentences[sentenceCount++] = tok;
        tok = strtok(NULL, ".");
    }
    printf("Summary:\n");
    for (int i = 0; i < sentenceCount; i++) {
        printf("%d. %s.\n", i + 1, sentences[i]);
    }
}

int main() {
    char inputText[MAX_INPUT];
    int numSentences;

    printf("Welcome to the Happy Text Summarizer!\n");
    printf("Enter the text you wish to summarize (max %d characters):\n", MAX_INPUT);
    fgets(inputText, MAX_INPUT, stdin);
    inputText[strcspn(inputText, "\n")] = 0;

    printf("How many sentences do you want to include in your summary?\n");
    scanf("%d", &numSentences);

    printSummary(inputText, numSentences);

    printf("Thank you for using the Happy Text Summarizer! Have a great day!\n");

    return 0;
}