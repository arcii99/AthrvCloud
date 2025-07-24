//FormAI DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to check if a string contains the word "spam".
int isSpam(char str[]) {
    char *word = "spam";
    char *ptr = strtok(str, " .,;:\t\n\r");
    while (ptr != NULL) {
        if (strcmp(ptr, word) == 0) {
            return 1;
        }
        ptr = strtok(NULL, " .,;:\t\n\r");
    }
    return 0;
}

// Main function to test the spam detection system.
int main() {
    char email[1000];
    printf("Enter your email message:\n");
    fgets(email, sizeof(email), stdin);
    if (isSpam(email)) {
        printf("This email is spam.\n");
    } else {
        printf("This email is not spam.\n");
    }
    return 0;
}