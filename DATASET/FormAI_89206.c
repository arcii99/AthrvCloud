//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int main() {
    char input[MAX_INPUT_LENGTH]; // user input
    char spam_words[][20] = { // list of spam words/phrases
        "earn money fast", "weight loss", "lottery winner", 
        "Nigeria", "urgent", "free gift", "limited time offer"
    };
    int spam_count = 0; // counter for number of spam words found
    
    printf("Enter your message: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // get user input
    
    for(int i = 0; i < sizeof(spam_words)/sizeof(spam_words[0]); i++) {
        if(strstr(input, spam_words[i]) != NULL) { // check if input contains spam word
            spam_count++; // increment spam counter
        }
    }
    
    if(spam_count > 0) { // if spam found
        printf("Warning: Your message contains %d spam word(s).\n", spam_count);
    } else { // if no spam found
        printf("Your message is spam-free.\n");
    }
    
    return 0;
}