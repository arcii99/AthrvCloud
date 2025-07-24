//FormAI DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of email
#define MAX_EMAIL_LENGTH 100

// Maximum number of spam keywords
#define MAX_SPAM_KEYWORDS 5

// Spam keywords
char spam_keywords[MAX_SPAM_KEYWORDS][20] = {"free", "money", "lottery", "prize", "offer"};

// Function to check if a given word is a spam keyword or not
int is_spam_keyword(char* word) {
    for(int i=0; i<MAX_SPAM_KEYWORDS; i++) {
        if(strcmp(word, spam_keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given email is a spam or not
int is_spam(char* email) {
    char temp_email[MAX_EMAIL_LENGTH];
    strcpy(temp_email, email);

    // Split email into words
    char* word = strtok(temp_email, " ");

    while(word != NULL) {
        if(is_spam_keyword(word)) {
            return 1;
        }
        word = strtok(NULL, " ");
    }

    return 0;
}

// Main function
int main() {
    char email[MAX_EMAIL_LENGTH];

    printf("Enter the email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);

    // Remove trailing newline character
    email[strcspn(email, "\n")] = 0;

    if(is_spam(email)) {
        printf("Email is a spam.\n");
    } else {
        printf("Email is not a spam.\n");
    }

    return 0;
}