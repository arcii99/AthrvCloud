//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>

int calculate_checksum(char *data, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }
    return ~(sum % 256);
}

int main() {
    char data[100] = "Hello, world!";
    int len = sizeof(data) / sizeof(char);
    int checksum = calculate_checksum(data, len);
    
    printf("Data: %s\n", data);
    printf("Checksum: %d\n", checksum);
    
    return 0;
}