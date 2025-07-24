//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    printf("GNU Prime Number Generator\n");
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        int j, is_prime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d, ", i);
        }
    }
    printf("End of list\n");
    return 0;
}