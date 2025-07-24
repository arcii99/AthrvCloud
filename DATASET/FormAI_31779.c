//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>

int main() {
    char message[50];
    printf("Enter your message (max 50 characters): ");
    scanf("%s", message);

    for (int i = 0; i < strlen(message); i++) {
        char curr_letter = message[i];

        if (curr_letter == ' ') {
            printf("     ");
        }
        else if (curr_letter == 'a' || curr_letter == 'A') {
            printf("  /\\  \n");
            printf(" /  \\ \n");
            printf("/____\\\n");
            printf("|    |\n");
            printf("|----|\n");
            printf("|    |\n");
        }
        else if (curr_letter == 'b' || curr_letter == 'B') {
            printf("|-----\n");
            printf("|     \\\n");
            printf("|-----|\n");
            printf("|     |\n");
            printf("|-----|\n");
            printf("|     |\n");
            printf("|-----|\n");
        }
        else if (curr_letter == 'c' || curr_letter == 'C') {
            printf("  ____\n");
            printf(" /    \\\n");
            printf("/      \\\n");
            printf("\\      /\n");
            printf(" \\____/\n");
        }
        // continue for the rest of the alphabet and other characters

    }

    return 0;
}