//FormAI DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXIMUM_LENGTH 100

void clean_buffer(char* buffer) {
    memset(buffer, 0, MAXIMUM_LENGTH);
}

int has_numb(char* buffer) {
    for (int i = 0; i < strlen(buffer); i++) {
        if (isdigit(buffer[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int count = 0;
    char message[MAXIMUM_LENGTH];
    while (count < 3) {
        printf("Enter a message: ");
        fgets(message, MAXIMUM_LENGTH, stdin);
        // check for spam keywords
        if (strstr(message, "buy now") || strstr(message, "limited time offer")) {
            printf("SPAM DETECTED\n");
            clean_buffer(message);
            count++;
            continue;
        }
        // check for excessive use of capital letters
        int capital_count = 0;
        for (int i = 0; i < strlen(message); i++) {
            if (isupper(message[i])) {
                capital_count++;
            }
        }
        if ((double)capital_count / strlen(message) > 0.3) {
            printf("Potential spam detected (excessive use of capital letters)\n");
            clean_buffer(message);
            count++;
            continue;
        }
        // check for presence of numbers
        if (has_numb(message)) {
            printf("Potential spam detected (presence of numbers)\n");
            clean_buffer(message);
            count++;
            continue;
        }
        printf("Message successfully sent\n");
        clean_buffer(message);
    }
    printf("Maximum spam attempts exceeded\n");
    return 0;
}