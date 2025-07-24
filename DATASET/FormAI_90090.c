//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: funny
#include <stdio.h>

// Let's make the program a little bit fun!

int main()
{
    printf("Welcome to the Checksum Calculator!\n");

    printf("Enter the number of bytes you want to calculate checksum for: ");

    int numBytes;
    scanf("%d", &numBytes);

    printf("\nAlrighty then! Let's get started...\n");

    int checksum = 0;
    int currentByte;

    for (int i = 0; i < numBytes; i++) {
        printf("Enter byte no.%d: \n", i + 1);
        scanf("%d", &currentByte);
        checksum += currentByte * (i + 1); // funny way of calculating checksum!
    }

    printf("\nCalculating checksum...\n");

    // Let's add some suspense here...
    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout); // flush the output buffer to show the dots
        usleep(200000); // wait for 0.2 seconds
    }

    printf("\n\nYour calculated checksum is: %d\n", checksum);

    // Let's add some Easter eggs!
    if (checksum >= 1000000) {
        printf("\nWow, your data is very secure! The checksum is more than 1 million!\n");
    } else if (checksum < 1000) {
        printf("\nUh oh, your checksum is less than 1000... Better double check your data!\n");
    } else {
        printf("\nYour data is safe with this checksum!\n");
    }

    printf("\nThanks for using the Checksum Calculator. Have a nice day!\n");

    return 0;
}