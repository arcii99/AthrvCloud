//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>
#define MAX_SIZE 100

int main() {
    unsigned char data[MAX_SIZE]; // array to hold data
    int i, length, sum = 0;

    // read the length of data
    printf("Enter the length of data: ");
    scanf("%d", &length);

    // read the data
    printf("Enter the data: ");
    for (i = 0; i < length; i++) {
        scanf("%hhx", &data[i]); // use %hhx format specifier to read hex values as unsigned char
    }

    // calculate the checksum
    for (i = 0; i < length; i++) {
        sum += data[i];
    }
    sum = ~sum + 1; // take 2's complement

    // print the checksum in hex format
    printf("Checksum: %02x\n", sum);

    return 0;
}