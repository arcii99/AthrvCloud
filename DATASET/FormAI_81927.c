//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char message[100];
    int i, j, spam_count = 0;

    printf("Enter message: ");
    fgets(message, 100, stdin);

    // convert message to lowercase
    for(i = 0; i < strlen(message); i++) {
        message[i] = tolower(message[i]);
    }

    // check for excessive use of question marks and exclamation marks
    for(i = 0; i < strlen(message); i++) {
        if(message[i] == '?' || message[i] == '!') {
            spam_count++;
        }
    }

    if(spam_count > 4) {
        printf("This message appears to be spam.");
    } else {
        // remove excess whitespace from the message
        char temp[100];
        j = 0;
        for(i = 0; i < strlen(message); i++) {
            if(message[i] != ' ') {
                temp[j++] = message[i];
            } else if(i > 0 && message[i-1] != ' ') {
                temp[j++] = ' ';
            }
        }
        temp[j] = '\0';

        // check for repeated characters
        int repeated_count = 0;
        for(i = 0; i < strlen(temp); i++) {
            if(isalpha(temp[i]) && temp[i] == temp[i+1] && temp[i] == temp[i+2]) {
                repeated_count++;
            }
        }

        if(repeated_count > 1) {
            printf("This message appears to be spam.");
        } else {
            printf("This message does not appear to be spam.");
        }
    }

    return 0;
}