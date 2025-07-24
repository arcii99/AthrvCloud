//FormAI DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000 //maximum input length

void summary(char input[]);

int main() {
    printf("Welcome to the Text Summarizer!\n");
    printf("Give me a paragraph or two and I'll summarize it for you!\n");
    char input[MAX_LEN] = ""; //initialize input string
    printf("Enter your text below:\n");
    fgets(input, MAX_LEN, stdin); //get user input
    summary(input); //call summarization function
    return 0;
}

void summary(char input[]) {
    char *word = strtok(input, " "); //initialize pointer to first word
    int count = 0; //initialize word count
    while(word != NULL) {
        count++; //increment word count
        if (count <= 10) { //display first 10 words
            printf("%s ", word);
        }
        word = strtok(NULL, " "); //move pointer to next word
    }
    if (count > 10) { //display summary if more than 10 words
        printf("...and that's the summary!");
    }
    else { //if 10 or less words, add a cheerful message
        printf("You're so concise! Keep up the good work!");
    }
}