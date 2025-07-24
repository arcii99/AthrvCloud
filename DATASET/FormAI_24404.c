//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>

// Function to calculate the sum of digits in a number
int digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to calculate the checksum
int checksum(char* data) {
    int sum = 0;
    int i = 0;
    while (data[i] != '\0') {
        sum += data[i];
        i++;
    }
    sum += digit_sum(i);
    return sum % 256;
}

int main() {
    char* data = "Hello, world!";
    printf("Checksum of '%s' is %d\n", data, checksum(data));
    return 0;
}