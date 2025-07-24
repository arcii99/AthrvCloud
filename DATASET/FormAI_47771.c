//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>

// Define the maximum length of the input text
#define MAX_LENGTH 1000

// Define the list of positive words
char positive_words[][20] = {"good", "awesome", "nice", "great", "excellent", "fantastic", "outstanding"};

// Define the list of negative words
char negative_words[][20] = {"bad", "terrible", "awful", "poor", "horrible", "disgusting", "worst"};

// Define a function to count how many times a word appears in the input text
int count_word(char *word, char *text) {
    int count = 0;
    char *pos = strstr(text, word);
    while (pos != NULL) {
        count++;
        pos = strstr(pos + 1, word);
    }
    return count;
}

// Define the main function
int main() {
    // Declare variables needed for the program to run
    char text[MAX_LENGTH];
    int positive_score = 0, negative_score = 0, total_score = 0;
    
    // Get input text from the user
    printf("Enter your text: ");
    fgets(text, MAX_LENGTH, stdin);
    
    // Loop through each word in the positive list and count how many times it appears in the input text
    for (int i = 0; i < sizeof(positive_words) / sizeof(positive_words[0]); i++) {
        int count = count_word(positive_words[i], text);
        positive_score += count;
    }
    
    // Loop through each word in the negative list and count how many times it appears in the input text
    for (int i = 0; i < sizeof(negative_words) / sizeof(negative_words[0]); i++) {
        int count = count_word(negative_words[i], text);
        negative_score += count;
    }
    
    // Calculate the total sentiment score by subtracting the negative score from the positive score
    total_score = positive_score - negative_score;
    
    // Print the sentiment score to the user
    printf("Sentiment score: %d\n", total_score);
    
    // Return 0 to indicate the program ran successfully
    return 0;
}