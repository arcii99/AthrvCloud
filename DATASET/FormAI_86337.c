//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {

    char text[1000], summary[500], word[100]; // declare variables for input text, summary, and a single word
    int i, text_len, summary_len = 0; // declare variables for loop iterations and lengths
    
    printf("Welcome to the Text Summarizer.\nPlease enter the text for summarization:\n");

    // take input text from user
    fgets(text, sizeof(text), stdin);
    
    // calculate length of input text
    text_len = strlen(text);
    
    // loop through the input text, word by word
    for (i=0; i<text_len; i++) {
        
        sscanf(&text[i], "%s", word); // scan for the current word
        
        // if the current word is more than 8 letters, add it to the summary
        if (strlen(word) > 8) {
            strcat(summary, word); // concatenate the word to the summary
            strcat(summary, " "); // add a space after the word
            summary_len += strlen(word) + 1; // update the length of the summary
        }
        
        // if the summary length is greater than 200, break the loop
        if (summary_len > 200) {
            break;
        }
        
        i += strlen(word); // skip to the next word in the input text
    }

    printf("\nYour text summary is:\n%s", summary); // print the summary

    return 0; // end the program
}