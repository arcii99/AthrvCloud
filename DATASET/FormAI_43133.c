//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>

void display_sequence(int n) {
    int a = 0, b = 1, c, i;

    printf("Fibonacci sequence up to %d:\n", n);

    for (i = 1; i <= n; i++) {
        putchar('[');
        printf("%5d", a);
        putchar(']');
        
        // futuristic animation
        putchar('\b'); putchar(' '); putchar('\b');
        putchar('\b'); putchar('|'); putchar('\b');
        putchar('\b'); putchar('/'); putchar('\b');
        putchar('\b'); putchar('-'); putchar('\b');
        putchar('\b'); putchar('\\'); putchar('\b');
        
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    display_sequence(n);

    return 0;
}