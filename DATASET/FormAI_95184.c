//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>

void printC() {
    printf(" _____\n");
    printf("/ ____|\n");
    printf("| |\n");
    printf("| |\n");
    printf("| |____\n");
    printf("\\_____|");
}

void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printC();
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the post-apocalyptic world!\n");
    printf("Printing a unique C-pattern in the world of chaos.\n");

    printf("Enter the size of the pattern (minimum 3): ");
    int n;
    scanf("%d", &n);

    if (n < 3) {
        printf("Invalid size, setting size to 3.\n");
        n = 3;
    }

    printPattern(n);

    printf("Printing complete! Stay safe out there.\n");
    return 0;
}