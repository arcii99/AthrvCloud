//FormAI DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spamCount = 0;

void checkForSpam(char *inputText) {
    char *spamWords[] = {"spam", "scam", "phishing", "fraud"};
    int numSpamWords = sizeof(spamWords) / sizeof(char *);

    for(int i = 0; i < numSpamWords; i++) {
        if(strstr(inputText, spamWords[i]) != NULL) {
            spamCount++;
            printf("SPAM ALERT: '%s' was detected as spam.\n", spamWords[i]);
        }
    }
}

int main() {
    char input[1000];

    printf("Enter your text: ");
    fgets(input, sizeof(input), stdin); // Read user input

    checkForSpam(input);

    if(spamCount == 0) {
        printf("No spam detected. Good job!");
    } else {
        printf("Total spam count detected: %d", spamCount);
    }

    return 0;
}