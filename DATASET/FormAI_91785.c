//FormAI DATASET v1.0 Category: Spam Detection System ; Style: intelligent
#include<stdio.h>
#include<string.h>

#define SPAM_THRESHOLD 0.5

float spam_probability(char* message) {
    int message_length = strlen(message);
    int spam_count = 0;
    float probability;

    for(int i = 0; i < message_length; i++) {
        if(message[i] == 's' || message[i] == 'S' || message[i] == 'p' || message[i] == 'P' || message[i] == 'a' || message[i] == 'A' || message[i] == 'm' || message[i] == 'M') {
            spam_count++;
        }
    }

    probability = (float)spam_count / message_length;

    return probability;
}

int main() {
    char message_input[500];

    printf("Enter your message:\n");
    fgets(message_input, 500, stdin);

    float spam_prob = spam_probability(message_input);

    if(spam_prob > SPAM_THRESHOLD) {
        printf("SPAM message detected!\n");
    } else {
        printf("No SPAM message detected.\n");
    }

    return 0;
}