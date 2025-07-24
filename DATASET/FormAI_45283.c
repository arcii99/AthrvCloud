//FormAI DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>

// function to check for spam keywords
int is_spam(char msg[]) {
    char keywords[10][20] = {"free", "lottery", "discount", "deal", "click here", "make money", "limited time", "offer", "win", "amazing"};
    int num_keywords = 10;
    int i, j, len;

    for (i = 0; i < num_keywords; ++i) {
        len = strlen(keywords[i]);
        for (j = 0; j < strlen(msg); ++j) {
            if (msg[j] == keywords[i][0]) {
                if (strncmp(msg+j, keywords[i], len) == 0) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    // prompt user for message and scan input
    char msg[1000];
    printf("Enter a message: ");
    scanf("%[^\n]s", msg);

    // check for spam keywords and output result
    if (is_spam(msg)) {
        printf("\nThis message is spam.\n");
    } else {
        printf("\nThis message is not spam.\n");
    }

    return 0;
}