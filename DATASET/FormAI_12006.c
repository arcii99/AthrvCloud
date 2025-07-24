//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

void summarize(char text[], int length) {
    char summary[length];
    char *words = strtok(text, " ");
    int count = 0;

    while (words != NULL) {
        strcat(summary, words);
        strcat(summary, " ");
        count += strlen(words);
        words = strtok(NULL, " ");
        
        if (count >= (length * 0.5)) { // summary should be half the length of the text
            break;
        }
    }
    
    printf("%s...", summary);
}

int main() {
    char text[] = "This is an example of a long piece of text that could use summarization in order to make it easier to read and understand. Sometimes, it can be difficult to stay focused when reading through long blocks of text, especially when the content is complex or technical. By summarizing the main points of the text, readers can quickly grasp the key messages without having to sift through unnecessary details. This program uses a simple algorithm to identify the most important words in a piece of text and to present a summary that is approximately half the length of the original text.";
    int length = strlen(text);
    summarize(text, length);
    return 0;
}