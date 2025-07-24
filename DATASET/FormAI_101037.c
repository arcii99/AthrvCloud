//FormAI DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

/* Function to check if a given string contains spam words */
int isSpam(char *message) {
    char *spamWords[] = {"viagra", "lottery", "free money", "prince", "inheritance", "debt consolidation"};
    int numSpamWords = sizeof(spamWords) / sizeof(spamWords[0]);
    int i = 0;
    for (i = 0; i < numSpamWords; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

/* Main function that prompts user for input and checks for spam */
int main() {
    char message[1000];
    printf("Please enter your message:\n");
    fgets(message, 1000, stdin);
    if (isSpam(message)) {
        printf("Your message contains spam!\n");
    } else {
        printf("Your message is safe.\n");
    }
    return 0;
}