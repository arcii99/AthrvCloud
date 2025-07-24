//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 1000
#define SPAM_THRESHOLD 0.5

int count_occurrences(char *string, char *substring) {
    int count = 0;
    char *tmp = string;

    while ((tmp = strstr(tmp, substring))) {
        count++;
        tmp += strlen(substring);
    }

    return count;
}

double check_spam(char *input) {
    // list of keywords that are commonly found in spam messages
    char *keywords[] = {"earn", "money", "investment", "opportunity", "limited time offer", "act now"};

    double spam_score = 0;
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_keywords; i++) {
        int occurrences = count_occurrences(input, keywords[i]);
        spam_score += (double) occurrences / (double) strlen(input);
    }

    return spam_score;
}

int main() {
    char input[MAX_INPUT_LEN];
    printf("Enter your message: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    double spam_score = check_spam(input);

    if (spam_score > SPAM_THRESHOLD) {
        printf("This message appears to be spam.\n");
    } else {
        printf("This message seems legit.\n");
    }

    return 0;
}