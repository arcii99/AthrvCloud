//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: high level of detail
#include <stdio.h>

int main()
{
    int data_size;
    printf("Enter the size of data: ");
    scanf("%d", &data_size);

    int data[data_size];
    printf("Enter the data: ");
    for (int i = 0; i < data_size; i++)
    {
        scanf("%d", &data[i]);
    }

    int sum = 0;
    for (int i = 0; i < data_size; i++)
    {
        sum += data[i];
    }

    int ones_complement = ~sum;
    int checksum = ones_complement & 0xFF;

    printf("Checksum: %d\n", checksum);

    return 0;
}