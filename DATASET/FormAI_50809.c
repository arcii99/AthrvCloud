//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
// Scene I: The Street of Variables

#include <stdio.h>
#include <string.h>

int main() {
    char message[50];
    int count = 0;
    printf("Enter a message: ");
    fgets(message, 50, stdin);

    // Scene II: The If Statement
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == 's') {
            count++;
        }
    }

    // Scene III: The Judge's Decision
    if (count > 0) {
        printf("This message contains spam!\n");
    } else {
        printf("This message is spam-free.\n");
    }

    return 0;
}