//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 1000 // Maximum number of characters per message
#define SPAM_THRESHOLD 0.2 // Minimum percentage of spam words in a message

char *spam[] = {"viagra", "lottery", "money", "inheritance", "deal", "prince", "wealth", "enlarge"}; // List of spam keywords
int spam_count = sizeof(spam)/sizeof(char*); // Number of spam keywords

float get_spam_ratio(char *message);
int is_spam(char *message);

int main() {
    char message[MAX_CHARACTERS];
    printf("Enter your message: ");
    fgets(message, MAX_CHARACTERS, stdin);
    if(is_spam(message)) {
        printf("Warning: This message may contain spam!");
    } else {
        printf("This message is spam-free.");
    }
    return 0;
}

float get_spam_ratio(char *message) {
    char *word;
    float spam_words = 0;
    float total_words = 0;
    word = strtok(message, " ,.-\n\r");
    while(word != NULL) {
        total_words++;
        for(int i = 0; i < spam_count; i++) {
            if(strcasecmp(word, spam[i]) == 0) {
                spam_words++;
                break;
            }
        }
        word = strtok(NULL, " ,.-\n\r");
    }
    return spam_words/total_words;
}

int is_spam(char *message) {
    float spam_ratio = get_spam_ratio(message);
    return (spam_ratio >= SPAM_THRESHOLD);
}