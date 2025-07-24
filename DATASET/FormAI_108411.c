//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to the C Alien Language Translator!\n");

    // Input from user
    char input[100];
    printf("Please enter a sentence in the C Alien Language:\n");
    fgets(input, 100, stdin);

    // Conversion process
    int i = 0;
    while (input[i] != '\n') {
        switch(input[i]) {
            case 'C':
                printf("K");
                break;
            case 'c':
                printf("k");
                break;
            case 'L':
                printf("Q");
                break;
            case 'l':
                printf("q");
                break;
            case 'G':
                printf("Z");
                break;
            case 'g':
                printf("z");
                break;
            case 'T':
                printf("D");
                break;
            case 't':
                printf("d");
                break;
            case 'P':
                printf("F");
                break;
            case 'p':
                printf("f");
                break;
            case 'J':
                printf("W");
                break;
            case 'j':
                printf("w");
                break;
            case 'S':
                printf("$");
                break;
            case 's':
                printf("#");
                break;
            default:
                printf("%c", input[i]);
        }
        i++;
    }

    // Goodbye message
    printf("\nThank you for using the C Alien Language Translator!\n");

    return 0;
}