//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char text[1000];
    int num_chars[128] = {0}; // array to hold the count of each character
    double p[128] = {0}; // array to store the probability of each character
    double entropy = 0; // variable to hold the entropy value
    
    printf("Enter some text: ");
    fgets(text, 1000, stdin); // read input from user
    
    // loop through each character and increment the count in the respective array index
    for (int i = 0; i < strlen(text); i++) {
        num_chars[text[i]]++;
    }
    
    // loop through the array of character counts and calculate the probability of each character
    for (int i = 0; i < 128; i++) {
        if (num_chars[i] != 0) {
            p[i] = (double)num_chars[i] / strlen(text);
        }
    }
    
    // loop through the array of probabilities and calculate the Shannon entropy
    for (int i = 0; i < 128; i++) {
        if (p[i] != 0) {
            entropy += -1 * p[i] * log2(p[i]);
        }
    }
    
    printf("\nThe Shannon entropy of the sentiment expressed in the text is: %f\n", entropy);
    
    return 0;
}