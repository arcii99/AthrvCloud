//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
/* Hey there! Welcome to my Sentiment Analysis Tool program in C! */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100];  // declare input string with max length of 100
    int score = 0; // initialize score to 0

    printf("Let's analyze some text!\n");
    printf("Enter the text you want to analyze: ");
    fgets(input, 100, stdin); // read input from user
    
    /* Here is where the magic happens! */
    for (int i = 0; i < strlen(input); i++) {
        /* Check for positive words */
        if (input[i] == 'h' && input[i+1] == 'a' && input[i+2] == 'p' && input[i+3] == 'p' && input[i+4] == 'y') {
            score += 2;
        }
        else if (input[i] == 'g' && input[i+1] == 'r' && input[i+2] == 'e' && input[i+3] == 'a' && input[i+4] == 't') {
            score += 3;
        }
        else if (input[i] == 'a' && input[i+1] == 'w' && input[i+2] == 'e' && input[i+3] == 's' && input[i+4] == 'o' && input[i+5] == 'm' && input[i+6] == 'e') {
            score += 4;
        }

        /* Check for negative words */
        else if (input[i] == 's' && input[i+1] == 'a' && input[i+2] == 'd') {
            score -= 2;
        }
        else if (input[i] == 't' && input[i+1] == 'e' && input[i+2] == 'r' && input[i+3] == 'r' && input[i+4] == 'i' && input[i+4] == 'b' && input[i+4] == 'l' && input[i+4] == 'e') {
            score -= 3;
        }
        else if (input[i] == 'h' && input[i+1] == 'o' && input[i+2] == 'r' && input[i+3] == 'r' && input[i+4] == 'i' && input[i+4] == 'b' && input[i+4] == 'l' && input[i+4] == 'e') {
            score -= 4;
        }
    }
    
    /* Print result based on the score */
    if (score > 0) {
        printf("Great news! This text has a positive sentiment with a score of %d.\n", score);
    }
    else if (score < 0) {
        printf("Sorry to hear that! This text has a negative sentiment with a score of %d.\n", score);
    }
    else {
        printf("This text has a neutral sentiment with a score of %d\n", score);
    }
    
    return 0; // Voila! We're done here!
}