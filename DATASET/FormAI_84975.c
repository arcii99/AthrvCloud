//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Function to check if a given string contains spam words
int isSpam(char *str) {
    char *spamWords[] = {"offer", "promotional", "win", "cash", "prize", "free", "limited time", "discount", "exclusive", "buy now", "act fast", "order now"};
    int i, j, len, spamCount = 0;

    len = strlen(str);

    for(i=0; i<12; i++) {
        for(j=0; j<len; j++) {
            if(str[j] == spamWords[i][0]) {
                if(strncmp(&str[j], spamWords[i], strlen(spamWords[i]))==0) {
                    spamCount++;
                    j+=strlen(spamWords[i])-1;
                }
            }
        }
    }

    if(spamCount > 2) // If more than two spam words are detected, return 1 indicating spam
        return 1;
    else
        return 0;
}

int main() {
    char email[500];

    printf("Enter email message: ");
    fgets(email, 500, stdin);

    if(isSpam(email)) {
        printf("This message is spam!");
    } else {
        printf("This message is not spam.");
    }

    return 0;
}