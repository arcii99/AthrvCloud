//FormAI DATASET v1.0 Category: Date and time ; Style: recursive
#include <stdio.h>
#include <time.h>

void displayTime(int sec);

int main()
{
    time_t now;

    time(&now);

    printf("Current date and time: %s", ctime(&now));

    displayTime(60);

    return 0;
}

void displayTime(int sec)
{
    time_t now;

    time(&now);

    printf("\nCurrent date and time after %d seconds: %s", sec, ctime(&now));

    if (sec != 0)
    {
        displayTime(sec - 10);
    }
}