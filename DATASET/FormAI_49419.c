//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>

void printC() {
    printf(" *****\n");
    printf("**    \n");
    printf("**    \n");
    printf("**    \n");
    printf(" *****\n");
}

void printA() {
    printf("  ***  \n");
    printf(" ** ** \n");
    printf("**   **\n");
    printf("*******\n");
    printf("**   **\n");
}

void printPattern() {
    printC();
    printA();
    printC();
    printA();
    printC();
    printA();
}

int main() {
    printf("Starting pattern printing...\n");

    printPattern();

    printf("Finished pattern printing.\n");

    return 0;
}