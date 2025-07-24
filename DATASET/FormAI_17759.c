//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <string.h>

// function to convert character to ascii art
void ascii_art(char c) {
    switch (c) {
        case 'a':
            printf("    /\\ \n");
            printf("   /  \\ \n");
            printf("  /----\\ \n");
            printf(" /      \\ \n");
            printf("/        \\ \n");
            break;
        case 'b':
            printf(" ____ \n");
            printf("|    \\ \n");
            printf("|____/ \n");
            printf("|    \\ \n");
            printf("|____/ \n");
            break;
        case 'c':
            printf("  ___ \n");
            printf(" /     \\ \n");
            printf("|       \\\n");
            printf("|        \n");
            printf(" \\_____/ \n");
            break;
        // add more cases here for other letters
        default:
            printf("      \n");
            printf("      \n");
            printf("      \n");
            printf("      \n");
            printf("      \n");
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        ascii_art(str[i]);
    }
    return 0;
}