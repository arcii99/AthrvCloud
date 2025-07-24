//FormAI DATASET v1.0 Category: Scientific ; Style: innovative
#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("The prime factors of %d are: ", n);
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    if (n > 1) {
        printf("%d", n);
    }
    printf("\n");
    return 0;
}