//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// Function to check if a given string is spam or not
int is_spam(char* str) {
    char* spam_words[] = {"buy", "now", "sale", "discount", "offer"};
    int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);
    int count = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        for (int i = 0; i < num_spam_words; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                count++;
            }
        }
        token = strtok(NULL, " ");
    }
    // If more than half of the words in the string are spam words, it is considered spam
    if (count > (num_spam_words / 2)) {
        return 1;
    }
    return 0;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    // Remove the newline character from the input string
    input[strlen(input) - 1] = '\0';
    if (is_spam(input)) {
        printf("This string is spam!\n");
    } else {
        printf("This string is not spam.\n");
    }
    return 0;
}