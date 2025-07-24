//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[500];
    printf("Enter a sentence: "); // prompting the user to enter a sentence
    fgets(str, 500, stdin); // reading the user input from standard input
    int len = strlen(str);
    if(str[len-1] == '\n'){ // removing the newline character at the end of the string
        str[len-1] = '\0';
    }
    char keywords[5][10] = {"happy", "sad", "angry", "excited", "depressed"}; // list of predefined keywords that denote different sentiments
    int sentimentvalues[5] = {5, -5, -10, 8, -7}; // corresponding sentiment values for each keyword

    int sentiment = 0;
    char* token = strtok(str, " "); // tokenizing the input sentence based on spaces
    while(token != NULL){
        for(int i = 0; i < 5; i++){
            if(strcasecmp(token, keywords[i]) == 0){ // checking if the token matches any of the predefined keywords
                sentiment += sentimentvalues[i]; // updating the sentiment value based on the matched keyword
            }
        }
        token = strtok(NULL, " ");
    }
    printf("The sentiment score of the sentence is: %d\n", sentiment); // printing the final sentiment score

    return 0;
}