//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter the message whose checksum you want to calculate: ");

    char input[100];
    scanf("%s", input);

    int checksum = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        checksum += (int)input[i];
    }

    printf("The checksum of your message is: %d", checksum);

    return 0;
}