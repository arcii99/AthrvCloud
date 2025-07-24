//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100
#define ASCII_ART_WIDTH 80

void draw_ascii_art(char c) {
    switch(c) {
        case 'A':
            printf("  _____  \n");
            printf(" / ____| \n");
            printf("| (___   \n");
            printf(" \\___ \\  \n");
            printf(" ____) | \n");
            printf("|_____/  \n");
            break;
        case 'B':
            printf(" _______ \n");
            printf("|  __ \\ \n");
            printf("| |__) |\n");
            printf("|  ___/ \n");
            printf("| |     \n");
            printf("|_|     \n");
            break;
        case 'C':
            printf("  ______ \n");
            printf(" /      \\\n");
            printf("|  $$$$$$\n");
            printf("| $$___  \n");
            printf("| $$___  \n");
            printf(" \\______\\\n");
            break;
        // Add more ASCII art for other letters and characters here
        default:
            printf("INVALID CHARACTER\n");
            break;
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter text to convert to ASCII art:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    int length = strlen(text);
    for(int i = 0; i < length; i++) {
        // Skip newline character at the end of the input
        if(text[i] == '\n') {
            continue;
        }
        
        draw_ascii_art(text[i]);
        printf("\n");
    }

    return 0;
}