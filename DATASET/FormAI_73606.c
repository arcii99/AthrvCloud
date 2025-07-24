//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int calculate_checksum(const char* data, size_t size)
{
    int sum = 0;

    // iterate through all bytes of the data and add them up
    for (size_t i = 0; i < size; i++)
    {
        sum += (int)data[i];
    }

    // reduce the sum to an 8-bit value by taking the two's complement
    return (~sum + 1) & 0xFF;
}

int main(int argc, char** argv)
{
    // check if the user provided a data string as argument
    if (argc < 2)
    {
        printf("Usage: checksum [data string]\n");
        return -1;
    }

    // read data string from arguments and calculate its checksum
    const char* data = argv[1];
    size_t size = strlen(data);
    int checksum = calculate_checksum(data, size);

    // print the data and the checksum
    printf("Data: %s\n", data);
    printf("Checksum: %d\n", checksum);

    return 0;
}