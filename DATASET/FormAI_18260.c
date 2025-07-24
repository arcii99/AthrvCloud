//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const char *fortune[] = {
        "You will have a great day!",
        "Good things are coming your way!",
        "You will meet someone special soon!",
        "Your dreams will come true!",
        "Take a chance, it will pay off!",
        "Success is just around the corner!",
        "Your hard work will pay off soon!"
    };
    int index;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    /* Generates a random index for the fortune array */
    index = rand() % 7;

    /* Prints the fortune to the console */
    printf("Your fortune for today: %s\n", fortune[index]);

    return 0;
}