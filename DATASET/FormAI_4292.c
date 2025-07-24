//FormAI DATASET v1.0 Category: Random ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Generate 10 random numbers between 1 and 100
    printf("Here are 10 random numbers between 1 and 100:\n");
    for (int i = 0; i < 10; i++) {
        int randomNumber = rand() % 100 + 1;
        printf("%d\n", randomNumber);
    }

    // Generate a random character
    char randomChar = 'A' + rand() % (('Z' - 'A') + 1);
    printf("The randomly generated character is: %c\n", randomChar);

    // Generate a random string of length 10
    char randomString[11]; // Maximum string length + null terminator
    for (int i = 0; i < 10; i++) {
        randomString[i] = 'a' + rand() % (('z' - 'a') + 1);
    }
    randomString[10] = '\0';
    printf("The randomly generated string is: %s\n", randomString);

    return 0;
}