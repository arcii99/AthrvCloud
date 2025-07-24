//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>
#define MAX 1000

char *text_summarizer(char *text) {
    char *summary = (char*)malloc(MAX*sizeof(char));
    memset(summary, '\0', MAX);
    char *sentence = strtok(text, "."); //splitting the text by sentences
    while(sentence != NULL) {
        char *word = strtok(sentence, " "); //splitting a sentence by words   
        int word_count = 0, sum_len = 0;
        while(word != NULL) {
            word_count++;
            sum_len += strlen(word);
            word = strtok(NULL, " ");
        }
        if(word_count > 6 && sum_len > 30) { //check for word and length limits
            strcat(summary, sentence);
            strcat(summary, ". "); //adding the sentence to summary with a period
        }
        sentence = strtok(NULL, ".");
    }
    return summary;
}

int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char *summary = text_summarizer(text);
    printf("Summary: %s\n", summary);
    free(summary);
    return 0;
}