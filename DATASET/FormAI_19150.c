//FormAI DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main()
{
    char input_string[100];
    int spam_count = 0;
    char *spam_words[] = {"buy", "free", "subscribe", "giveaway"};

    printf("Welcome to your Spam Detection System!\n");

    // Get input string
    printf("Please enter your message:\n");
    fgets(input_string, 100, stdin);

    // Convert to lowercase
    for(int i = 0; i < strlen(input_string); i++) {
        input_string[i] = tolower(input_string[i]);
    }

    // Check for spam words
    for(int i = 0; i < sizeof(spam_words)/sizeof(spam_words[0]); i++) {
        char *result = strstr(input_string, spam_words[i]);
        if(result != NULL) {
            spam_count++;
        }
    }

    // Print result
    if(spam_count > 0) {
        printf("This message is spam!\n");
    }
    else {
        printf("This message is not spam.\n");
    }

    return 0;
}