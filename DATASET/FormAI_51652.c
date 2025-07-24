//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include<stdio.h>
#include<string.h>

//Function to check if the message contains any spam keywords
int containsSpam(char *message, int i, char *keywords[], int numKeywords) {
    if (i == numKeywords) {
        return 0;
    } else {
        if (strstr(message, keywords[i])) {
            return 1;
        } else {
            return containsSpam(message, i+1, keywords, numKeywords);
        }
    }
}

int main() {
    char *keywords[] = {"buy", "cheap", "get rich quick", "money back guarantee", "limited time offer"};
    int numKeywords = sizeof(keywords)/sizeof(char*);
    char message[1000];

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    //Remove the newline character from the end of the message
    message[strcspn(message, "\n")] = 0;

    if (containsSpam(message, 0, keywords, numKeywords)) {
        printf("This message contains spam.\n");
    } else {
        printf("This message does not contain spam.\n");
    }

    return 0;
}