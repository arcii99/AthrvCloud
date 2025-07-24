//FormAI DATASET v1.0 Category: Recursive ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int mystery(int n);

int main() {
    int x = 10;
    printf("The mystery result for %d is %d\n", x, mystery(x));
    return 0;
}

int mystery(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n % 2 == 0) {
        return n - mystery(n / 2);
    }
    else {
        return n + mystery((3 * n + 1) / 2);
    }
}