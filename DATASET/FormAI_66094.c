//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000  // Maximum length of the message

/*
    This is a simple spam detection system that checks if a message contains certain spam keywords.
    If a keyword is found, the message is flagged as spam.
*/

int main() {
    char message[MAX_LENGTH]; // The message to be checked
    char spam_keywords[5][20] = {"spam", "viagra", "lottery", " Nigerian prince", "make money online"}; // List of spam keywords
    int i, j, found;

    printf("Enter a message:\n");
    fgets(message, MAX_LENGTH, stdin); // Get the message from the user

    for(i=0; i<5; i++) { // Loop through the spam keywords
        found = 0; // Initialize found flag to false
        for(j=0; j<strlen(message); j++) { // Loop through the message
            if(message[j] == spam_keywords[i][0]) { // Check if the first character of the keyword matches the current character in the message
                if(strncmp(&message[j], spam_keywords[i], strlen(spam_keywords[i])) == 0) { // Check if the keyword is present in the message
                    found = 1; // Set found flag to true
                    break;
                }
            }
        }
        if(found) { // If the spam keyword is found, print the spam message and exit
            printf("\n***SPAM DETECTED***\n");
            return 0;
        }
    }

    printf("\nNo spam detected.\n");

    return 0;
}