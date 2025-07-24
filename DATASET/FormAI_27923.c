//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>

void cheer(int n) {
    if (n <= 0)
        return;
    printf("Hip hip hooray!\n");
    cheer(n-1);
}

void main() {
    printf("Let's cheer for recursion!\n");
    cheer(3);
    printf("Great job!\n");
}