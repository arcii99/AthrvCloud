//FormAI DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spamCount = 0;

int checkKeyword(char *message, char *keyword) {
    char *found = strstr(message, keyword);
    if (found) {
        return 1;
    }
    return 0;
}

int checkUppercase(char *message) {
    int uppercaseCount = 0;
    int i;

    for (i = 0; i < strlen(message); i++) {
        if (isupper(message[i])) {
            uppercaseCount++;
        }
    }

    if (uppercaseCount > strlen(message) / 2) {
        return 1;
    }

    return 0;
}

void spamCheck(char *message) {
    if (checkKeyword(message, "credit") && checkKeyword(message, "card")) {
        spamCount++;
    }

    if (checkKeyword(message, "make") && checkKeyword(message, "money")) {
        spamCount++;
    }

    if (checkUppercase(message)) {
        spamCount++;
    }
}

int main() {
    char message[1000];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    spamCheck(message);

    if (spamCount > 1) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not likely spam.\n");
    }

    return 0;
}