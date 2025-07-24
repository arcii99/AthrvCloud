//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>

void printStars(int);
void printBox(int);

int main() {
    int n;
    printf("Enter a positive number: ");
    scanf("%d", &n);

    printf("\nPrinting a box made up of stars:\n");
    printBox(n);

    return 0;
}

void printStars(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    // Recursive case
    printf("*");
    printStars(n-1);
}

void printBox(int n) {
    // Top line
    printStars(n);
    printf("\n");

    // Middle lines
    for (int i = 0; i < n-2; i++) {
        printf("*");
        for (int j = 0; j < n-2; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // Bottom line
    printStars(n);
}