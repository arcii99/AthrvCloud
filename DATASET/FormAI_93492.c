//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char *conspiracyTheories[10] = {
        "The government is hiding aliens in Area 51.",
        "The moon landing was faked by NASA.",
        "Chemtrails are being used to control our minds.",
        "The earth is actually flat, not round.",
        "Elvis Presley is still alive and living in hiding.",
        "The Illuminati is secretly controlling the world.",
        "The world will end in 2022.",
        "The Beatles were created by the CIA as propaganda.",
        "The Titanic never actually sank, it was a conspiracy.",
        "The Loch Ness monster is real and being kept hidden by the government."
    };

    srand(time(NULL));

    int randomNum = rand() % 10;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Your conspiracy theory for the day is: %s\n", conspiracyTheories[randomNum]);

    return 0;
}