//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>

// Function to check if the given string contains spam
int isSpam(char* str) {
    char* spam_words[] = {"buy", "viagra", "free", "$$$", "click here", "earn money"};

    for(int i=0; i < 6; i++) {
        if(strstr(str, spam_words[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;

    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] == ' ') {
            count++;
        }
    }

    // Increment the count for the last word
    return count+1;
}

int main() {
    char email[500], subject[100], body[400];
    int spam_flag = 0, num_words;

    printf("Enter the email subject: ");
    fgets(subject, 100, stdin);
    subject[strcspn(subject, "\n")] = '\0'; // Remove the newline character

    printf("Enter the email body:\n");
    fgets(body, 400, stdin);
    body[strcspn(body, "\n")] = '\0'; // Remove the newline character

    // Concatenate the subject and body to form the complete email and check for spam
    strcpy(email, subject);
    strcat(email, " ");
    strcat(email, body);
    spam_flag = isSpam(email);

    if(spam_flag) {
        printf("The email contains spam!\n");
    } else {
        printf("The email is free from spam.\n");
    }

    // Count the number of words in the email body
    num_words = countWords(body);
    printf("The email body contains %d words.\n", num_words);

    return 0;
}