//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <string.h>

// function to print ASCII art of characters
void ascii_art(char c) {
    switch(c) {
        case 'A':
        case 'a':
            printf("    AA    \n");
            printf("  AAAAAA  \n");
            printf(" AA    AA \n");
            printf("AA      AA\n");
            printf("AA      AA\n");
            break;
        case 'B':
        case 'b':
            printf("BBBBBBB  \n");
            printf("BB    BB \n");
            printf("BBBBBBB  \n");
            printf("BB    BB \n");
            printf("BBBBBBB  \n");
            break;
        case 'C':
        case 'c':
            printf("  CCCCCC  \n");
            printf(" CC      \n");
            printf("CC       \n");
            printf(" CC      \n");
            printf("  CCCCCC  \n");
            break;
        // add more characters here
        case '\n':
            printf("\n");
            break;
        default:
            printf("         \n");
            printf("  %c is not supported yet!  \n", c);
            printf("         \n");
    }
}

int main() {
    // prompt user to enter a message
    printf("Enter your message: ");
    char message[100];
    fgets(message, sizeof(message), stdin);

    printf("\nHere is your message in ASCII art:\n");

    // iterate through the message and print ASCII art for each character
    for(int i = 0; i < strlen(message); i++) {
        ascii_art(message[i]);
    }

    return 0;
}