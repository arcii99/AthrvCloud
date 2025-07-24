//FormAI DATASET v1.0 Category: Funny ; Style: introspective
#include <stdio.h>

int main() {
    printf("I am a C program.\n");
    int i;
    char* keywords[6] = {"if", "else", "for", "while", "do", "switch"};
    char* quotes[3] = {"I think, therefore I am.", "To be or not to be, that is the question.", "All work and no play makes Jack a dull boy."};
    printf("I am going to list some keywords and famous quotes to show off my knowledge.\n");

    printf("Keywords in C:\n");
    for (i = 0; i < 6; i++) {
        printf("%s\n", keywords[i]);
    }

    printf("Famous quotes:\n");
    for (i = 0; i < 3; i++) {
        printf("%s\n", quotes[i]);
    }

    printf("I am pretty impressed with myself, I must say.\n");
    return 0;
}