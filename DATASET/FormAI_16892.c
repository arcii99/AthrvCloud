//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <string.h>

#define SPAM_KEYWORDS_SIZE 5
#define SPAM_THRESHOLD 3

char *SPAM_KEYWORDS[SPAM_KEYWORDS_SIZE] = {
    "lottery",
    "free",
    "money",
    "prize",
    "click here"
};

int main()
{
    char email[1000];
    int spamScore = 0;

    printf("Enter your email message: \n");
    fgets(email, sizeof(email), stdin);

    // Check email for spam keywords
    for (int i = 0; i < SPAM_KEYWORDS_SIZE; i++) {
        if (strstr(email, SPAM_KEYWORDS[i]) != NULL) {
            spamScore++;
        }
    }

    // Determine if email is spam
    if (spamScore >= SPAM_THRESHOLD) {
        printf("This email is likely spam. Spam score: %d\n", spamScore);
    } else {
        printf("This email is not spam. Spam score: %d\n", spamScore);
    }

    return 0;
}