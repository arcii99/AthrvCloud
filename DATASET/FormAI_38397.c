//FormAI DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>
#define SPAM_KEYWORDS {"free", "buy now", "click here", "limited time offer", "discount"}

int spam_checker(char message[]) {
    int i;
    char *keywords[] = SPAM_KEYWORDS;
    for(i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if(strstr(message, keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[100];
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    if(spam_checker(message) == 1) {
        printf("This message contains spam.\n");
    }
    else {
        printf("This message does not contain spam.\n");
    }

    return 0;
}