//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: minimalist
#include <stdio.h>

int calculateChecksum(char *data, int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += *(data+i);
    }
    return sum % 256;
}

int main()
{
    char data[100];
    int size;

    printf("Enter the data: ");
    scanf("%s", data);

    for(size = 0; *(data+size) != '\0'; size++);

    int checksum = calculateChecksum(data, size);

    printf("The checksum for the data is: %d", checksum);

    return 0;
}