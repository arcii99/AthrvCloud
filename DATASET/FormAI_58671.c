//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int calculate_checksum(char *str, int len);

int main() {
    char data[100];  // array to store the data
    int len, checksum;

    printf("Enter the input data: ");
    fgets(data, 100, stdin);  // read input from user
    len = strlen(data);
    checksum = calculate_checksum(data, len);

    printf("Checksum value: %d\n", checksum);

    return 0;
}

int calculate_checksum(char *str, int len) {
    int checksum = 0;

    for (int i = 0; i < len; i++) {
        checksum += (int) str[i];
    }

    return checksum % 256;
}