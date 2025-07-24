//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBanner(char* message) {
    int length = strlen(message);
    printf("\n");
    for (int i = 0; i < length + 4; i++) {
        printf("*");
    }
    printf("\n* %s *\n", message);
    for (int i = 0; i < length + 4; i++) {
        printf("*");
    }
    printf("\n\n");
}

void printCharacter(char c) {
    switch(c) {
        case 'A':
        case 'a':
            printf("  /\\  \n");
            printf(" /  \\ \n");
            printf("/____\\n");
            break;
        case 'B':
        case 'b':
            printf("|||||\n");
            printf("||__+\n");
            printf("||__/ \n");
            printf("||||  \n");
            printf("+--+  \n");
            break;
        case 'C':
        case 'c':
            printf("  ____\n");
            printf("/____ \\\n");
            printf("\\_____/\n");
            break;
        case 'D':
        case 'd':
            printf("|||||\n");
            printf("||__+\n");
            printf("||   \\\n");
            printf("||__/ \n");
            printf("||||  \n");
            printf("+--+  \n");
            break;
        case 'E':
        case 'e':
            printf("||||||\n");
            printf("||____\n");
            printf("||____\n");
            printf("||||||\n");
            break;
        case 'F':
        case 'f':
            printf("||||||\n");
            printf("||____\n");
            printf("||____\n");
            printf("||    \n");
            break;
        case 'G':
        case 'g':
            printf("  ____\n");
            printf("/____ \\\n");
            printf("\\__|||\\\n");
            printf("  |||/\n");
            break;
        case 'H':
        case 'h':
            printf("||   ||\n");
            printf("||___||\n");
            printf("||   ||\n");
            break;
        case 'I':
        case 'i':
            printf("|||||\n");
            printf("  ||  \n");
            printf("  ||  \n");
            printf("|||||\n");
            break;
        case 'J':
        case 'j':
            printf("  ||||\n");
            printf("   || \n");
            printf("__ || \n");
            printf("\\_||/\n");
            break;
        case 'K':
        case 'k':
            printf("||  / \\\n");
            printf("|| /   \\\n");
            printf("|| \\___/\n");
            break;
        case 'L':
        case 'l':
            printf("||    \n");
            printf("||    \n");
            printf("||____\n");
            printf("||||||\n");
            break;
        case 'M':
        case 'm':
            printf("||\\  /||\n");
            printf("|| \\/ ||\n");
            printf("||    ||\n");
            break;
        case 'N':
        case 'n':
            printf("||\\   ||\n");
            printf("|| \\  ||\n");
            printf("||  \\ ||\n");
            break;
        case 'O':
        case 'o':
            printf("  ____\n");
            printf("/____ \\\n");
            printf("\\    /\n");
            printf(" \\__/ \n");
            break;
        case 'P':
        case 'p':
            printf("|||||\n");
            printf("||__+\n");
            printf("||   \n");
            printf("||    \n");
            break;
        case 'Q':
        case 'q':
            printf("  ____\n");
            printf("/____ \\\n");
            printf("\\    /\n");
            printf(" \\__\\_\n");
            break;
        case 'R':
        case 'r':
            printf("|||||\n");
            printf("||__+\n");
            printf("|| \\ \n");
            printf("||  \\ \n");
            break;
        case 'S':
        case 's':
            printf("  ____\n");
            printf("/____ \n");
            printf("     )\n");
            printf("\\____/\n");
            break;
        case 'T':
        case 't':
            printf("||||||\n");
            printf("  ||  \n");
            printf("  ||  \n");
            break;
        case 'U':
        case 'u':
            printf("||   ||\n");
            printf("||   ||\n");
            printf(" \\___/ \n");
            break;
        case 'V':
        case 'v':
            printf("\\   /\n");
            printf(" \\ /\n");
            printf("  V\n");
            break;
        case 'W':
        case 'w':
            printf("||   ||\n");
            printf("|| _ ||\n");
            printf(" \\ V /\n");
            break;
        case 'X':
        case 'x':
            printf("\\  /\n");
            printf(" \\/ \n");
            printf("/\\  \n");
            break;
        case 'Y':
        case 'y':
            printf("\\  /\n");
            printf(" \\/ \n");
            printf("  || \n");
            break;
        case 'Z':
        case 'z':
            printf("||||||\n");
            printf("   / \n");
            printf("  /  \n");
            printf("||||||\n");
            break;
        default:
            printf("\n");
            break;
    }
}

int main() {
    char message[100];
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline character

    printBanner(message);

    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        printCharacter(message[i]);
    }

    printf("\n");

    return 0;
}