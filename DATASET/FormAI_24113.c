//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>

int main() {
    int n, sum = 0, num;
    printf("Enter the number of integers to calculate checksum for: ");
    scanf("%d", &n);

    printf("Enter the integers:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
    }

    // Calculating and printing the checksum
    int checksum = ~(sum % 256);
    printf("The checksum is: %d", checksum);

    return 0;
}