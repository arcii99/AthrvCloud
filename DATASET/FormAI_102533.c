//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int spamCount = 0;

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    // Check for keywords that indicate spam message
    if (strstr(message, "free") != NULL || strstr(message, "offer") != NULL) {
        spamCount++;
    }

    // Check for excessive use of exclamation marks or capital letters
    int numExclamations = 0;
    int numCapitalLetters = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '!') {
            numExclamations++;
        }
        if (message[i] >= 'A' && message[i] <= 'Z') {
            numCapitalLetters++;
        }
    }
    if (numExclamations > 5 || numCapitalLetters > strlen(message) / 4) {
        spamCount++;
    }

    // Check for repeated characters or all caps letters in subject line
    char subject[] = "Subject:";
    char* subjectPos = strstr(message, subject);
    if (subjectPos != NULL) {
        subjectPos += strlen(subject);
        while (*subjectPos == ' ') {
            subjectPos++; // skip any whitespace after subject:
        }
        if (strstr(subjectPos, "ALL CAPS") != NULL || strstr(subjectPos, "!!!!") != NULL) {
            spamCount++;
        }
        for (int i = 0; i < strlen(subjectPos); i++) {
            if (subjectPos[i] == subjectPos[i + 1] && (subjectPos[i] < '0' || subjectPos[i] > '9')) {
                spamCount++;
                break;
            }
        }
    }

    // Print output based on spam count
    printf("\n");
    if (spamCount == 0) {
        printf("This message is not spam.\n");
    } else if (spamCount == 1) {
        printf("This message may be spam. Please review before responding.\n");
    } else {
        printf("This message is likely spam. Do not respond or click on any links.\n");
    }

    return 0;
}