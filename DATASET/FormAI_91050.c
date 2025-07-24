//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char msg[1000];
    int numCaps = 0;
    int numExclamations = 0;
    int numDollarSigns = 0;

    printf("Please enter your message:\n");
    fgets(msg, 1000, stdin);

    for (int i=0; i<strlen(msg); i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            numCaps++;
        }
        if (msg[i] == '!') {
            numExclamations++;
        }
        if (msg[i] == '$') {
            numDollarSigns++;
        }
    }

    if (numCaps > 10 && numExclamations > 3 && numDollarSigns > 0) {
        printf("This message is likely spam.\n");
        printf("Please do not include all caps, excessive exclamation marks, or dollar signs in messages.\n");
    } else {
        printf("This message is likely not spam.\n");
    }

    return 0;
}