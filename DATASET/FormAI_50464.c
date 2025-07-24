//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[1000];
    int length, i, count = 1, spam = 0;
    
    printf("Enter your message: ");
    fgets(message, 1000, stdin);
    length = strlen(message);
    
    // Check for excessive capital letters
    for (i = 0; i < length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            count++;
        }
    }
    if (count > length / 2) {
        spam = 1;
    }
    
    // Check for common spam words
    char* token = strtok(message, " \n\r\t");
    while (token != NULL) {
        if (strcmp(token, "money") == 0 || strcmp(token, "free") == 0 || strcmp(token, "subscribe") == 0) {
            spam = 1;
            break;
        }
        token = strtok(NULL, " \n\r\t");
    }

    // Check for excessive exclamation marks or question marks
    count = 0;
    for (i = 0; i < length; i++) {
        if (message[i] == '!' || message[i] == '?') {
            count++;
        }
    }
    if (count > 3) {
        spam = 1;
    }
    
    // Output result
    if (spam) {
        printf("Your message is likely spam.\n");
    } else {
        printf("Your message is not spam.\n");
    }
    
    return 0;
}