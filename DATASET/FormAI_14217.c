//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int data[MAX_SIZE];
    int sum = 0, checksum = 0, i, n;

    printf("Enter the number of elements in the data: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        fprintf(stderr, "Error: maximum number of elements exceeded\n");
        exit(1);
    }

    printf("Enter the data:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        sum += data[i];
    }

    checksum = ~(sum % 256);

    printf("Calculated checksum: %d\n", checksum);

    return 0;
}