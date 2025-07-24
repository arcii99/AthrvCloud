//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#define MAX_INPUT_SIZE 200
#define SPAM_PROB_THRESHOLD 0.8

float calc_spam_prob(char *input, int input_len) {
    float spam_prob = 0.0;
    char *ptr;

    // Checking for certain suspicious words in the input
    ptr = strstr(input, "free money");
    if (ptr != NULL) {
        spam_prob += 0.3;
    }
    ptr = strstr(input, "act now");
    if (ptr != NULL) {
        spam_prob += 0.2;
    }
    ptr = strstr(input, "make money fast");
    if (ptr != NULL) {
        spam_prob += 0.4;
    }

    // Checking for excessive use of uppercase characters
    int num_uppercase = 0;
    for (int i = 0; i < input_len; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            num_uppercase++;
        }
    }
    if (num_uppercase > 0 && ((float) num_uppercase / (float) input_len) > 0.3) {
        spam_prob += 0.2;
    }

    return spam_prob;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the input message:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    int input_len = strlen(input) - 1; // ignroing the newline character

    float spam_prob = calc_spam_prob(input, input_len);
    if (spam_prob >= SPAM_PROB_THRESHOLD) {
        printf("This message is likely a spam. Spam Probability = %.2f\n", spam_prob);
    } else {
        printf("This message does not seem like a spam. Spam Probability = %.2f\n", spam_prob);
    }

    return 0;
}