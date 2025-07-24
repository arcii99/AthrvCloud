//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int checksumCalculator(char *datastring, int size) {
    int sum = 0;
    int i;

    for (i = 0; i < size; i++)
        sum += (int)datastring[i];

    return sum % 256;
}

int main() {
    char data[] = "Hello World!";
    int checksum = checksumCalculator(data, sizeof(data));

    printf("The checksum of the data is: %d\n", checksum);

    return 0;
}