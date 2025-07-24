//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
    char message[] = "This is a sample message!"; // the message we'll be working on
    printf("Original message: %s\n", message);

    int message_length = strlen(message);

    // reverse the message
    for (int i = 0; i < message_length/2; i++) {
        char temp = message[i];
        message[i] = message[message_length - i - 1];
        message[message_length - i - 1] = temp;    
    }

    printf("Reversed message: %s\n", message);

    // find the index of the first space in the message
    int space_index = -1;
    for (int i = 0; i < message_length; i++) {
        if (message[i] == ' ') {
            space_index = i;
            break;
        }
    }

    if (space_index != -1) {
        // capitalize the first letter of every word
        message[0] = toupper(message[0]);
        for (int i = space_index + 1; i < message_length; i++) {
            if (message[i-1] == ' ') {
                message[i] = toupper(message[i]);
            }
        }

        printf("Capitalized message: %s\n", message);
    }

    return 0;
}