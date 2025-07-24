//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 0.7

double spamProbability(char* message);

int main() {
    char message[1000];
    printf("Enter message: ");
    fgets(message, 1000, stdin);

    double probability = spamProbability(message);

    if (probability >= THRESHOLD) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not likely spam.\n");
    }

    return 0;
}

double spamProbability(char* message) {
    int i, upperCount = 0, digitCount = 0, specialCount = 0, length = strlen(message);

    for (i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            upperCount++;
        }

        if (message[i] >= '0' && message[i] <= '9') {
            digitCount++;
        }

        if (message[i] == '!' || message[i] == '?' || message[i] == '&' || message[i] == '$' ) {
            specialCount++;
        }
    }

    double upperProb = (double) upperCount / length;
    double digitProb = (double) digitCount / length;
    double specialProb = (double) specialCount / length;

    double probability = 0.25 * upperProb + 0.25 * digitProb + 0.5 * specialProb;

    return probability;
}