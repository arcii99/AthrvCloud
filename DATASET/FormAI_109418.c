//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Fortune Teller Messages
    char* messages[] = {
        "You will travel to a far-off land in the near future",
        "A great opportunity will present itself in the near future",
        "You will find true love in the coming months",
        "You will be successful in all of your future endeavors",
        "The stars are aligned in your favor; expect good things to come your way",
        "You will receive unexpected wealth in the near future",
        "You will receive a promotion at work in the coming months",
        "Your next adventure will change your life forever",
        "Your hard work will pay off in the near future",
        "Good news is on its way to you soon"
    };

    // Get random index
    int index = rand() % 10;

    // Print message to user
    printf("Greetings! I am the Automated Fortune Teller. Here is your fortune: %s\n", messages[index]);

    return 0;
}