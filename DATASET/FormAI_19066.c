//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int happy_counter = 0;
    int sad_counter = 0;
    printf("Enter a sentence:\n");
    fgets(input, 100, stdin); // Takes input from user
    strtok(input, "\n"); // Removes trailing newline character
    char* token = strtok(input, " "); // Tokenizes input
    char* happy_words[] = {"happy", "joy", "excited", "ecstatic", "gleeful", "jubilant", "delighted", "thrilled", "content", "pleased", "elated", "emotional", "overjoyed"};
    char* sad_words[] = {"sad", "miserable", "depressed", "unhappy", "despairing", "gloomy", "melancholy", "despondent", "downcast", "dismal", "wretched", "disheartened", "heartbroken"};
    while (token != NULL) {
        for(int i=0; i<13; i++) {
            if(strcmp(token, happy_words[i]) == 0) {
                happy_counter++; //If the word exists in database then increase happy_counter
            }
            if(strcmp(token, sad_words[i]) == 0) {
                sad_counter++; //If the word exists in database then increase sad_counter
            }
        }
        token = strtok(NULL, " ");
    }
    printf("Number of happy words: %d\nNumber of sad words: %d\n", happy_counter, sad_counter);
    if(happy_counter > sad_counter) {
        printf("This sentence seems happy.\n"); //If happy_counter > sad_counter then it will print happy message
    } else if(happy_counter < sad_counter) {
        printf("This sentence seems sad.\n"); //If sad_counter > happy_counter then it will print sad message
    } else {
        printf("This sentence seems neutral.\n"); //If sad_counter == happy_counter then it will print neutral message
    }
    return 0;
}