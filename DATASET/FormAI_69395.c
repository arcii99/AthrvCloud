//FormAI DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>

/* Function to check if a message contains spam keywords */
int contains_spam(char *message)
{
    char *keywords[5] = {"buy", "cheap", "win", "cash", "discount"};
    int i;
    char *token;

    /* Split the message into words using whitespace as delimiter */
    token = strtok(message, " ");

    while (token != NULL) {
        for (i=0; i<5; i++) {
            if (strcmp(token, keywords[i]) == 0)
                return 1;
        }
        token = strtok(NULL, " ");
    }

    return 0;
}

int main()
{
    char message[1000];

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    if (contains_spam(message)) {
        printf("Spam detected!\n");
    } else {
        printf("Message is clean.\n");
    }

    return 0;
}