//FormAI DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int spamCount = 0, hamCount = 0;
    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter a message:\n");

    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "\n") == 0) {
            break;
        }

        if (strstr(input, "buy now") != NULL || strstr(input, "make money fast") != NULL) {
            printf("SPAM DETECTED!\n");
            spamCount++;
        } else {
            printf("Message is not spam, it has been sent safely.\n");
            hamCount++;
        }
    }

    printf("Scan complete.\n");
    printf("Number of spam messages detected: %d\n", spamCount);
    printf("Number of non-spam messages detected: %d\n", hamCount);

    return 0;
}