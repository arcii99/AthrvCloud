//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>

int calculate_checksum(char *data) {
    int i, sum = 0;
    for (i = 0; data[i] != '\0'; i++) {
        sum += (int)data[i];
    }
    return sum % 256;
}

int main() {
    char data[100];
    int checksum;
    printf("Enter data: ");
    gets(data);
    checksum = calculate_checksum(data);
    printf("Checksum: %d\n", checksum);
    return 0;
}