//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>

void printA() {
    printf("  /\\\n");
    printf(" /  \\\n");
    printf("/____\\\n");
    printf("|    |\n");
    printf("|    |\n");
}

void printB() {
    printf(" ____\n");
    printf("|    \\\n");
    printf("|     |\n");
    printf("|____/\n");
    printf("|    \\\n");
    printf("|     \\\n");
    printf("|______\\\n");
}

void printC() {
    printf("  ____\n");
    printf(" /    \\\n");
    printf("|      \n");
    printf("|      \n");
    printf("|      \n");
    printf(" \\____/\n");
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case 'a':
            case 'A':
                printA();
                break;
            case 'b':
            case 'B':
                printB();
                break;
            case 'c':
            case 'C':
                printC();
                break;
            default:
                printf("   /\n");
                printf("  /  \n");
                printf(" /    \\\n");
                printf("/______\\\n");
                break;
        }
    } 

    return 0;
}