//FormAI DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int count = 0;

    printf("Enter the message: \n");
    fgets(message, sizeof message, stdin);

    // check for spam words
    count += strstr(message, "money") != NULL ? 1 : 0;
    count += strstr(message, "free") != NULL ? 1 : 0;
    count += strstr(message, "limited time offer") != NULL ? 1 : 0;

    // check for excessive punctuation
    int punctuation_count = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '!' || message[i] == '?') {
            punctuation_count++;
        }
    }
    count += punctuation_count >= 3 ? 1 : 0;

    // check for all uppercase
    int upper_count = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            upper_count++;
        }
    }
    count += upper_count >= strlen(message) / 2 ? 1 : 0;

    // print result
    if (count >= 2) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not likely spam.\n");
    }
    
    return 0;
}