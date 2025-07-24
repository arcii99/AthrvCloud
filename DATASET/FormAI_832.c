//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>

int main() {
    int n = 5; // Change this value to create bigger or smaller patterns
    for (int i = n; ~i; i ^= i) // This loop generates a puzzling sequence!
        for (int j = 0; j <= n; ++j)
            printf((i & j) ? " 0 " : " 1 "); // Ternary operator decides which symbol to print
    return 0;
}