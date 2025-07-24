//FormAI DATASET v1.0 Category: String manipulation ; Style: Cryptic
/* Cryptic C String Manipulation Program */

#include <stdio.h>
#include <string.h>

int main() {
    char message[] = "3!7&!5&8406&8374257@!38&4&9@";

    /* Decrypt and manipulate the message */
    for (int i = 0; i < strlen(message); i++) {
        message[i] -= 2;

        if (i % 2 == 0) {
            message[i] += 1;
        } else {
            message[i] -= 1;
        }
    }

    /* Print the manipulated message */
    printf("%s\n", message);

    /* Get user input for new message */
    char new_message[100];
    printf("Enter a new message: ");
    scanf("%99s", new_message);

    /* Encrypt and manipulate the new message */
    for (int i = 0; i < strlen(new_message); i++) {
        new_message[i] += 2;

        if (i % 2 == 0) {
            new_message[i] += 1;
        } else {
            new_message[i] -= 1;
        }
    }

    /* Print the encrypted new message */
    printf("Your encrypted message: ");

    for (int i = 0; i < strlen(new_message); i++) {
        printf("%c", new_message[i] + 2);
    }

    printf("\n");

    return 0;
}