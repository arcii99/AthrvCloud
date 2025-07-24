//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char data[100];
    int checksum = 0;
    int i = 0;

    printf("Enter data: ");
    scanf("%s", data);

    while (data[i] != '\0')
    {
        checksum += (int) data[i];
        i++;
    }

    printf("Checksum: %d\n", checksum);

    return 0;
}