//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100]; //declare a character array to hold input sentence
    int happyCount = 0, sadCount = 0; //initialize the count of happy and sad words
    
    printf("Please enter a sentence: ");
    scanf("%[^\n]", sentence); //allow user to input a sentence including spaces
    
    //split the input sentence into individual words
    char *word = strtok(sentence, " ");
    
    //loop through each word in the sentence
    while (word != NULL) {
        //check if the word is Happy or sad
        if (strcmp(word, "Happy") == 0 || strcmp(word, "happy") == 0 || strcmp(word, "joyful") == 0 || strcmp(word, "Joyful") == 0 || strcmp(word, "excited") == 0 || strcmp(word, "Excited") == 0) {
            happyCount++;
        } else if (strcmp(word, "sad") == 0 || strcmp(word, "Sad") == 0 || strcmp(word, "depressed") == 0 || strcmp(word, "Depressed") == 0 || strcmp(word, "unhappy") == 0 || strcmp(word, "Unhappy") == 0) {
            sadCount++;
        }
        word = strtok(NULL, " ");
    }
    
    //print the sentiment analysis result
    if (happyCount > sadCount) {
        printf("The sentence is positive.\n");
    } else if (happyCount < sadCount) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }
    
    return 0;
}