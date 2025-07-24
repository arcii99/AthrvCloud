//FormAI DATASET v1.0 Category: Spam Detection System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SPAM_WORDS 5 // Maximum number of spam words to check against
#define MAX_WORD_LENGTH 20 // Maximum length of each spam word

int is_spam(char *message);

int main()
{
    char message[1000]; // Maximum length of message
    printf("Enter your message:\n");
    fgets(message, 1000, stdin); // Get message input from user
    
    if(is_spam(message)){
        printf("This message contains spam.\n");
    } else {
        printf("This message is clean.\n");
    }

    return 0;
}

int is_spam(char *message)
{
    char spam_words[MAX_SPAM_WORDS][MAX_WORD_LENGTH] = {"buy", "money", "free", "win", "lottery"}; // Hardcoded spam words
    char *word; // Pointer to each word in the message
    
    word = strtok(message, " ,."); // Tokenize message based on spaces, commas, and periods
    
    while(word != NULL){
        for(int i=0; i<MAX_SPAM_WORDS; i++){
            if(strcasecmp(word, spam_words[i]) == 0){ // Case-insensitive string comparison
                return 1; // Found spam word
            }
        }
        word = strtok(NULL, " ,."); // Move to next word in the message
    }
    
    return 0; // No spam words found
}