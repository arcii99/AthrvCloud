//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SPAM_WORDS 10

int main() {
    char input[100];
    int count = 0;
    char spamWords[MAX_SPAM_WORDS][10] = {
        "spam",
        "viagra",
        "lottery",
        "prize",
        "money",
        "inheritance",
        "wealth",
        "congratulations",
        "free",
        "offer"
    };
    
    // Prompt user for input
    printf("Please enter your message: ");
    fgets(input, 100, stdin);
    
    // Check if input contains any spam words
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strstr(input, spamWords[i]) != NULL) {
            count++;
        }
    }
    
    // Determine if message is spam or not
    if (count >= 2) {
        printf("Your message has been identified as spam. Please try again.\n");
    } else {
        printf("Your message has been successfully sent.\n");
    }
    
    return 0;
}