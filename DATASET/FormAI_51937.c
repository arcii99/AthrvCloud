//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// Declare a function that recursively generates a random number between 0 and 10 and prints it
void generateRandomNumber(int recursion_level, bool *done)
{
    if (*done)
        return;

    int randomNum = rand() % 10;
    printf("Random number generated at recursion level %d: %d\n", recursion_level, randomNum);

    if (randomNum == 0)
    {
        printf("Stopping recursion at level %d...\n", recursion_level);
        *done = true;
        return;
    }

    // Simulate asynchronous behavior by sleeping for a randomly generated time
    int sleepTime = rand() % 3 + 1;
    printf("Sleeping for %d second(s)...\n\n", sleepTime);
    sleep(sleepTime);

    generateRandomNumber(recursion_level + 1, done);
}

int main()
{
    bool done = false;
    srand(time(NULL));
    generateRandomNumber(0, &done);
    printf("Program has completed successfully.\n");

    return 0;
}