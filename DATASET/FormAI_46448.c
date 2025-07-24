//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>

int main() {
    char command[100];
    printf("Enter a command: ");
    scanf("%s", command);

    if (strcmp(command, "whoami") == 0) {
        printf("You is who you is.\n");
    } else if (strcmp(command, "make me a sandwich") == 0) {
        printf("No, make it yourself.\n");
    } else if (strcmp(command, "howdy") == 0) {
        printf("Howdy pardner!\n");
    } else if (strcmp(command, "knock knock") == 0) {
        printf("Who's there?\n");
    } else if (strcmp(command, "echo") == 0) {
        char text[100];
        printf("Enter some text: ");
        scanf("%s", text);
        printf("You said: %s\n", text);
    } else {
        printf("Sorry, I don't recognize that command.\n");
    }

    return 0;
}