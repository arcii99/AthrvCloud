//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main()
{
    int checksum = 0;
    char input[100];

    printf("Enter input string: ");
    scanf("%s", input);

    for (int i=0; i<strlen(input); i++)
    {
        checksum += (int)input[i];
    }

    printf("\nChecksum: %d\n", checksum);

    return 0;
}