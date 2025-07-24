//FormAI DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>

int main() {
    int n = 5;
    // Printing the top half part
    for (int i = n; i >= 1; i--) {
        printf("%*c", i, ' '); // Printing the left spaces
        for (int j = 1; j <= i + n - 1; j++) {
            if (j <= i) {
                printf("%c", '*'); // Printing asterisks for the left part
            } else {
                printf("%c", '+'); // Printing plus signs for the right part
            }
        }
        printf("\n");
    }

    // Printing the bottom half part
    for (int i = 2; i <= n; i++) {
        printf("%*c", i, ' '); // Printing the left spaces
        for (int j = 1; j <= i + n - 1; j++) {
            if (j <= i) {
                printf("%c", '+'); // Printing plus signs for the left part
            } else {
                printf("%c", '*'); // Printing asterisks for the right part
            }
        }
        printf("\n");
    }

    return 0;
}