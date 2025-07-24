//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int choice = rand() % 7;

    if(choice == 0) {
        printf("Did you know that the moon landing was faked by the government to win the space race?");
    }

    else if(choice == 1) {
        printf("Have you ever noticed that birds aren't real? They're actually government drones spying on us!");
    }

    else if(choice == 2) {
        printf("The earth is actually flat and the NASA has been lying to us for years!");
    }

    else if(choice == 3) {
        printf("The government is secretly putting chemicals in the tap water that are turning the frogs gay!");
    }

    else if(choice == 4) {
        printf("The Illuminati controls everything, and they're planning to take over the world!");
    }

    else if(choice == 5) {
        printf("The world is actually run by lizard people, and they're hiding in plain sight!");
    }

    else {
        printf("The government is hiding evidence of alien life from us, and they're planning a massive cover-up!");
    }

    return 0;
}