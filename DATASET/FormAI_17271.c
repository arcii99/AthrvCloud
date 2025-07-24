//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 1000 // Maximum length of input string
#define SPAM_KEYWORDS {"buy", "now", "limited", "offer"} // Array of spam keywords 

int is_spam(char *input);

int main() {
    char input[MAX_STRING_LENGTH]; // Input string
    printf("Enter your message: "); 
    fgets(input, MAX_STRING_LENGTH, stdin); // Taking input from user
    
    if(is_spam(input)) {
        printf("SPAM Detected!\n"); // If spam detected
    } else {
        printf("NOT a SPAM!\n"); // If not spam
    }
    return 0;
}

int is_spam(char *input) {
    char *spam_keywords[] = SPAM_KEYWORDS; // Array of spam keywords
    int i;
    for(i = 0; i < sizeof(spam_keywords)/sizeof(char*); i++) {
        if(strstr(input, spam_keywords[i])) { // If keyword found in input string
            return 1; // Return true
        }
    }
    return 0; // Return false, if no spam keyword found
}