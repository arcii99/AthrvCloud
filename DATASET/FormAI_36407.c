//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sentimentAnalysis(char *input_string) {
    // Initializing the variables for counting positive and negative words
    int positive_count = 0, negative_count = 0;
    char positive_words[10][50] = {{'g','o','o','d'}, {'e','x','c','e','l','l','e','n','t'}, {'a','m','a','z','i','n','g'}, {'t','h','e','b','e','s','t'}, {'h','a','p','p','y'}, {'l','o','v','e'}};
    char negative_words[10][50] = {{'b','a','d'}, {'t','e','r','r','i','b','l','e'}, {'w','o','r','s','t'}, {'s','a','d'}, {'h','a','t','e'}, {'d','i','s','l','i','k','e'}};

    // Converting input string to lowercase for ease of comparison
    for(int i=0; i<strlen(input_string); i++) {
        input_string[i] = tolower(input_string[i]);
    }

    // Counting the positive words
    for(int i=0; i<6; i++) {
        char *p = strstr(input_string, positive_words[i]);
        while(p != NULL) {
            positive_count++;
            p = strstr(p+1, positive_words[i]);
        }
    }

    // Counting the negative words
    for(int i=0; i<6; i++) {
        char *p = strstr(input_string, negative_words[i]);
        while(p != NULL) {
            negative_count++;
            p = strstr(p+1, negative_words[i]);
        }
    }

    // Calculating the total sentiment score
    int sentiment_score = positive_count - negative_count;

    // Checking if the sentiment is positive, negative or neutral
    if(sentiment_score > 0) {
        printf("The sentiment of the given text is Positive.\n");
    }
    else if(sentiment_score < 0) {
        printf("The sentiment of the given text is Negative.\n");
    }
    else {
        printf("The sentiment of the given text is Neutral.\n");
    }
}

int main() {
    // Test Cases
    char text1[] = "I love to eat pizza.";
    char text2[] = "I hate going to the dentist.";
    char text3[] = "The movie was good but the ending was bad.";
    
    printf("Text1: %s\n", text1);
    sentimentAnalysis(text1);

    printf("Text2: %s\n", text2);
    sentimentAnalysis(text2);

    printf("Text3: %s\n", text3);
    sentimentAnalysis(text3);

    return 0;
}