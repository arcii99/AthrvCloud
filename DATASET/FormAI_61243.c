//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

unsigned int calculateChecksum(const char* data, size_t size)
{
    unsigned int sum = 0;
    const unsigned char* buffer = (const unsigned char*) data;

    for (size_t i = 0; i < size; ++i)
    {
        sum += buffer[i];
    }

    sum = ~(sum - 1);
    return sum;
}

int main()
{
    char data[MAX_SIZE];
    size_t size;

    printf("Enter data to calculate checksum: ");
    fgets(data, MAX_SIZE, stdin);

    for (size = 0; data[size] != '\0'; ++size);

    unsigned int checksum = calculateChecksum(data, size - 1);

    printf("\nCalculated checksum: 0x%08X\n", checksum);

    return 0;
}