//FormAI DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    char input_text[1000]; // array for input text
    char summary[100]; // array for summary text
    int i, j=0, len, word_count=0, sentence_count=0;

    printf("Enter the text:\n");
    fgets(input_text, sizeof(input_text), stdin); // input text

    len = strlen(input_text);

    for(i=0; i<len; i++) {
        if(input_text[i] == ' ') {
            word_count++;
        }
        else if(input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            sentence_count++;
        }
    }

    word_count++; // need to update word count at end of text

    int target = word_count / 10; // set target summary length
    if(target == 0) { // in case input is too short
        target = 1;
    }

    for(i=0; i<len; i++) {
        if(input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            summary[j++] = input_text[i]; // add sentence-ending punctuation to summary
            if(sentence_count <= target) { // if target summary length is met
                break;
            }
            sentence_count--;
        }
        else if(summary[j-1] == '.' && input_text[i] == ' ') { //ensure proper grammar
            // do nothing
        }
        else {
            summary[j++] = input_text[i];
        }
    }

    printf("\nSummary:\n%s", summary); // print summary

    return 0;
}