//FormAI DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to detect spam in the given message.
int is_spam(char *message) {
    int n = strlen(message);
    int cnt = 0, num_of_digits = 0;

    // Check if message has too many digits and alphanumeric characters.
    for(int i = 0; message[i]; ++i) {
        if(isalpha(message[i]) || isdigit(message[i]))
            ++cnt;
        if(isdigit(message[i]))
            ++num_of_digits;
    }
    if(cnt/n > 0.6 && num_of_digits/n > 0.4)
        return 1;

    // Check if message contains specific words/phrases considered as spam.
    char *keywords[] = {"buy now", "limited time offer", "double your", "opportunity", "cash", "earn"};
    for(int i = 0; i < 6; ++i) {
        if(strstr(message, keywords[i]) != NULL)
            return 1;
    }

    return 0;
}

// Main function to run the program.
int main() {
    char message[300];

    printf("Enter your message: ");
    fgets(message, sizeof message, stdin);
    // Remove trailing newline from message.
    message[strcspn(message, "\n")] = 0;

    if(is_spam(message))
        printf("This message is spam.\n");
    else
        printf("This message is not spam.\n");

    return 0;
}