//FormAI DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkSpam(char message[]) {
    char *keywords[4] = {"buy", "discount", "sale", "limited time offer"}; // list of keywords to check
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]); // number of keywords
    char *str = strtok(message, " "); // tokenize message with space delimiter
    bool isSpam = false; // flag to indicate if message is spam

    while (str != NULL && !isSpam) {
        for (int i = 0; i < numKeywords; i++) {
            if (strcmp(str, keywords[i]) == 0) {
                isSpam = true; // set flag to true if keyword found
                break; // stop checking keywords if found
            }
        }
        str = strtok(NULL, " "); // continue tokenizing
    }

    return isSpam; // return flag
}

int main() {
    char message[100]; // assume message length is at most 100 characters

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin); // read message from input

    if (checkSpam(message)) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0; // exit program
}