//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_MSG_LENGTH 100

int main() {
    char message[MAX_MSG_LENGTH];
    int i, uppercase_count = 0, digit_count = 0, special_count = 0;

    printf("Please enter a message:\n");
    fgets(message, MAX_MSG_LENGTH, stdin);

    // Convert the message to uppercase
    for (i = 0; message[i] != '\0'; i++) {
        message[i] = toupper(message[i]);
    }
    
    // Check for spam keywords
    if (strstr(message, "BUY NOW") != NULL || strstr(message, "FREE MONEY") != NULL) {
        printf("SPAM message detected!\n");
        return 0;
    }

    // Count the number of uppercase letters, digits, and special characters
    for (i = 0; message[i] != '\0'; i++) {
        if (isupper(message[i])) {
            uppercase_count++;
        } else if (isdigit(message[i])) {
            digit_count++;
        } else if (!isspace(message[i])) {
            special_count++;
        }
    }

    // Determine if the message is suspicious based on character counts
    if (digit_count + special_count > uppercase_count) {
        printf("Suspicious message detected!\n");
    } else {
        printf("Message is not suspicious.\n");
    }

    return 0;
}