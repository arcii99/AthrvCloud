//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Alan Touring
#include <stdio.h>

int main() {
    char data[100];
    int checksum = 0;
    int i;

    printf("Enter data: ");
    scanf("%s", data);

    for (i = 0; data[i] != '\0'; i++) {
        checksum += data[i];
    }

    checksum = ~(checksum);

    printf("Checksum: %d\n", checksum);

    return 0;
}