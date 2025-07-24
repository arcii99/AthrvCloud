//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLetter(char letter);
void printWord(char *word);
void printLine(char *text);

int main() {
    char input[255];
    printf("Welcome to the ASCII art generator!\n");
    printf("Please enter the text you want to generate in ASCII art:");
    fgets(input, 255, stdin);
    input[strcspn(input, "\n")] = 0;
    printf("\n");
    printLine(input);
    printf("\n");
    return 0;
}

void printLetter(char letter) {
    switch (letter)
    {
        case 'a':
            printf("  /\\   \n");
            printf(" /  \\  \n");
            printf("/____\\ \n");
            printf("\\    / \n");
            printf(" \\  /  \n");
            printf("  \\/   \n");
            break;
        case 'b':
            printf(" ____  \n");
            printf("|    \\ \n");
            printf("|___  |  \n");
            printf("|    \\| \n");
            printf("|____/ \n");
            break;
        case 'c':
            printf("  ___  \n");
            printf(" /   \\ \n");
            printf("|      \n");
            printf("|      \n");
            printf(" \\___/  \n");
            break;
        case 'd':
            printf(" ____  \n");
            printf("|    \\ \n");
            printf("|     | \n");
            printf("|     | \n");
            printf("|____/ \n");
            break;
        case 'e':
            printf(" _____ \n");
            printf("|      \n");
            printf("|___   \n");
            printf("|      \n");
            printf("|_____ \n");
            break;
        default:
            printf("        \n");
            printf("        \n");
            printf("        \n");
            printf("        \n");
            printf("        \n");
            break;
    }
}

void printWord(char *word) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        printLetter(word[i]);
    }
}

void printLine(char *text) {
    int length = strlen(text);
    char word[255];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if ((text[i] == ' ' && i > 0) || i == length - 1) {
            if (i == length - 1) {
                word[j] = text[i];
                word[j+1] = '\0';
            } else {
                word[j] = '\0';
            }
            printWord(word);
            j = 0;
        } else {
            word[j] = text[i];
            j++;
        }
    }
}