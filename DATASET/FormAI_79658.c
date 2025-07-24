//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include<stdio.h>
#include<string.h>

int main(){

    char input_text[200];
    int num_of_words = 0, num_of_characters = 0, num_of_lines = 0;

    printf("Enter the text for Sentiment Analysis:\n");

    fgets(input_text, sizeof(input_text), stdin);

    num_of_lines++;

    for(int i=0; i<strlen(input_text); i++){
        if(input_text[i] == ' '){
            num_of_words++;
        }

        if(input_text[i] == '\n'){
            num_of_lines++;
        }
    }

    num_of_words++;

    num_of_characters = strlen(input_text) - (num_of_lines - 1);

    printf("\nNumber of words in the text = %d", num_of_words);
    printf("\nNumber of characters in the text = %d", num_of_characters);
    printf("\nNumber of lines in the text = %d", num_of_lines);

    int sentiment_score = num_of_words + num_of_characters - num_of_lines;

    if(sentiment_score > 0){
        printf("\nSentiment is Positive! Happy analyzing :)\n");
    }
    
    else if(sentiment_score < 0){
        printf("\nSentiment is Negative! Stay Calm and Carry On (-_-)\n");
    }

    else{
        printf("\nSentiment is Neutral! Analyze some more :|\n");
    }

    return 0;

}