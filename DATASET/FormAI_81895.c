//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 100 // maximum length of a message
#define SPAM_THRESHOLD 0.6 // spam threshold to determine if a message is spam or not

// function to calculate the similarity between two strings
double calculateSimilarity(char *msg1, char *msg2) {
    int len1 = strlen(msg1);
    int len2 = strlen(msg2);
    int count = 0;

    for(int i=0; i<len1; i++) {
        for(int j=0; j<len2; j++) {
            if(msg1[i] == msg2[j]) {
                count++;
            }
        }
    }

    double similarity = ((double)count) / (((double)len1 + (double)len2) / 2);
    return similarity;
}

int main() {
    // initialize variables
    char msg[MAX_MSG_LEN];
    double spamCount = 0;
    double totalCount = 0;
    double spamProbability = 0;

    // read input from user
    printf("Enter a message (type 'exit' to quit):\n");
    fgets(msg, MAX_MSG_LEN, stdin);
    msg[strcspn(msg, "\n")] = 0; // remove newline character

    while(strcmp(msg, "exit") != 0) {
        // read message from user
        totalCount++;

        // check if message is spam
        if(spamProbability > SPAM_THRESHOLD) {
            printf("This message is SPAM.\n");
            spamCount++;
        } else {
            printf("This message is NOT SPAM.\n");
        }

        // update spam probability
        spamProbability = (spamProbability*(totalCount-1) + calculateSimilarity(msg, "spam")) / totalCount;

        // read input from user
        printf("Enter a message (type 'exit' to quit):\n");
        fgets(msg, MAX_MSG_LEN, stdin);
        msg[strcspn(msg, "\n")] = 0; // remove newline character
    }

    // print results
    printf("\nSPAM DETECTION SYSTEM RESULTS\n");
    printf("Total messages analyzed: %.0f\n", totalCount);
    printf("Total spam messages detected: %.0f\n", spamCount);
    printf("Spam probability threshold: %.2f\n", SPAM_THRESHOLD);
    printf("Overall spam probability: %.2f\n", spamProbability);

    return 0;
}