//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to the Checksum Calculator! \n");
    printf("Enter a string: ");

    char input[100];
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    int sum = 0;

    for(int i=0; i<len; i++)
    {
        sum += (int)input[i];
    }

    int checksum = 255 - sum;

    printf("The checksum for \"%s\" is: %d \n", input, checksum);

    return 0;
}