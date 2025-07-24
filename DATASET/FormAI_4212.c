//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Surrealist C Spam Detection System example program
int main() {
    char message[100];

    printf("Welcome to the Surrealist Spam Detection System!\n");
    printf("Enter your message here:\n");
    fgets(message, 100, stdin);

    // Check if message contains spam
    if (strstr(message, "the sky is purple") != NULL) {
        printf("Warning: suspicious message! The sky is not purple.\n");
    } else if (strstr(message, "butterflies in my soup") != NULL) {
        printf("Warning: suspicious message! Butterflies do not belong in soup.\n");
    } else if (strstr(message, "elephants on the ceiling") != NULL) {
        printf("Warning: suspicious message! Elephants are too heavy to be on ceilings.\n");
    } else if (strstr(message, "rainbows in my pocket") != NULL) {
        printf("Warning: suspicious message! Rainbows cannot fit inside pockets.\n");
    } else if (strstr(message, "unicorns in the garden") != NULL) {
        printf("Warning: suspicious message! Unicorns do not exist in reality.\n");
    } else {
        printf("This message does not contain spam. Carry on.\n");
    }

    return 0;
}