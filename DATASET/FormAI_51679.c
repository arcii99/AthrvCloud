//FormAI DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Function to check if the email contains any spam words
int isSpam(char email[]) {
    char spamWords[5][20] = {"buy", "enlarge", "money", "limited time", "make money now"};

    for (int i = 0; i < 5; i++) {
        if (strstr(email, spamWords[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char email[1000];

    printf("Enter an email: ");
    scanf("%s", email);

    if (isSpam(email)) {
        printf("Your email contains spam words.\n");
    } else {
        printf("Your email does not contain any spam words.\n");
    }

    return 0;
}