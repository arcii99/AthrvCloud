//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int calculate_checksum(char *data, int len) {
    int i, sum = 0;

    for (i = 0; i < len; i++) {
        sum += data[i];

        if (sum > 0xFF) {
            sum -= 0xFF;
        }
    }

    return (0xFF - sum);
}

int main() {
    char data[] = "This is a test message";
    int len = sizeof(data) - 1;
    int checksum = calculate_checksum(data, len);
    
    printf("Message: %s\n", data);
    printf("Checksum: %02X\n", checksum);

    return 0;
}