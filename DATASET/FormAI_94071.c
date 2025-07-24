//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include<stdio.h>

void printLetter(char letter);

int main() {
    char input[100];
    printf("Enter a word or phrase: ");
    fgets(input, 100, stdin);
    for(int i = 0; input[i] != '\0'; i++) {
        printLetter(input[i]);
    }
    return 0;
}

void printLetter(char letter) {
    switch (letter) {
        case 'A':
        case 'a':
            printf("     /\\     \n");
            printf("    /  \\    \n");
            printf("   /    \\   \n");
            printf("  /------\\  \n");
            printf(" /        \\ \n");
            printf("/          \\\n");
            break;
        case 'B':
        case 'b':
            printf(" ----------- \n");
            printf("|           |\n");
            printf("| --------- \n");
            printf("|           |\n");
            printf("| --------- \n");
            printf("|           |\n");
            printf(" ----------- \n");
            break;
        case 'C':
        case 'c':
            printf("  /------\\  \n");
            printf(" /          \\\n");
            printf("|            \n");
            printf("|            \n");
            printf("|            \n");
            printf(" \\          /\n");
            printf("  \\------/  \n");
            break;
        //continue with D, E, F, etc.
        default:
            printf(" ");
            break;
    }
}