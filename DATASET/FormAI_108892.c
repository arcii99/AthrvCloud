//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void print_char(char c) {
    switch(c) {
        case 'A':
        case 'a':
            printf("    /\\   \n   /  \\  \n  /----\\ \n /      \\\n");
            break;
        case 'B':
        case 'b':
            printf(" |-----\n |     \\\n |------\\\n |       |\n |------/\n");
            break;
        case 'C':
        case 'c':
            printf("   _____\n /      \\\n|         \n|         \n \\_____/\n");
            break;
        case 'D':
        case 'd':
            printf("|-----\\\n|      |\n|      |\n|      |\n|-----/\n");
            break;
        case 'E':
        case 'e':
            printf(" ______\n|______|\n|       \n|______\n|______|\n");
            break;
        case 'F':
        case 'f':
            printf(" ______\n|______|\n|       \n|       \n|       \n");
            break;
        default:
            printf("\n");
            break;
    }
}

void print_text_art(char* text) {
    int i;
    for(i = 0; text[i] != '\0'; i++) {
        print_char(text[i]);
        printf("\n");
    }
}

int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);
    print_text_art(input);
    return 0;
}