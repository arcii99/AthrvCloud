//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to identify sentiment of given text
void identifySentiment(char *text){
    char *posWords[] = {"good", "great", "excellent", "awesome", "fantastic"};   // array of positive words
    char *negWords[] = {"bad", "terrible", "awful", "horrible", "disappointing"};   // array of negative words

    int posCount = 0, negCount = 0;   // variables to store count of positive and negative words

    // loop through each word in the text
    char *word = strtok(text, " ");   // split text into individual words using space as delimiter
    while(word != NULL){
        // check if word is in positive words array
        for(int i=0; i<5; i++){
            if(strcmp(word, posWords[i]) == 0){
                posCount++;   // increment count of positive words
            }
        }
        // check if word is in negative words array
        for(int i=0; i<5; i++){
            if(strcmp(word, negWords[i]) == 0){
                negCount++;   // increment count of negative words
            }
        }
        word = strtok(NULL, " ");   // get next word
    }

    // check sentiment based on count of positive and negative words
    if(posCount > negCount){
        printf("The text has a positive sentiment!\n");
    }
    else if(negCount > posCount){
        printf("The text has a negative sentiment.\n");
    }
    else{
        printf("The sentiment of the text is neutral.\n");
    }
}

int main(){
    char text[100];   // variable to store input text from user

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Enter some text to analyze: ");
    fgets(text, 100, stdin);   // get input text from user
    text[strcspn(text, "\n")] = '\0';   // remove newline character from end of text

    identifySentiment(text);   // call function to identify sentiment of text

    return 0;
}