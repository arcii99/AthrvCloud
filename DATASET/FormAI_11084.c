//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>

int csum(int num) {
    if (num == 0) {
        return 0;
    }
    else {
        return (num % 10) + csum(num / 10);
    }
}

int main() {
    int n, checksum;
    printf("Enter a number: ");
    scanf("%d", &n);

    checksum = csum(n);

    printf("Checksum of %d is %d\n", n, checksum);

    return 0;
}