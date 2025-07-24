//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

int main() {
    int bytes[100], checksum = 0, n;
    printf("Enter the number of bytes: ");
    scanf("%d", &n);
    printf("Enter %d bytes (space separated): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bytes[i]);
        checksum += bytes[i];
    }
    printf("Checksum = %d\n", checksum % 256);

    return 0;
}