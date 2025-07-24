//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int year, day;
    time_t t;

    // Initialization of random number generator
    srand((unsigned) time(&t));

    // Generating a random year between 1000 and 1500
    year = rand() % 501 + 1000;

    // Generating a random day of the year
    day = rand() % 365 + 1;

    // Printing the date in a medieval style
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You have arrived in the year %d.\n", year);
    printf("It is the %dth day of the year.\n", day);
    printf("You find yourself in a medieval village.\n");

    // Interaction with the villagers
    printf("You approach a villager and ask for information.\n");
    printf("Villager: Welcome, stranger! What brings you to our humble village?\n");

    // Asking for directions to the nearest castle
    printf("You: I am an adventurer and I am looking for the nearest castle. Could you direct me?\n");
    printf("Villager: Ah, the castle of Lord Byron is the closest one. You can find it to the north-east of here, about 10 miles away.\n");

    // Offering help to the villager
    printf("You: Thank you for your help. Is there anything I can do for you?\n");
    printf("Villager: Well, we do have a problem with rats in our granary. If you could help us get rid of them, we would be very grateful.\n");

    // Accepting the quest
    printf("You: Very well, I accept your quest. Where is the granary located?\n");
    printf("Villager: It's just outside the village, near the river. You can't miss it.\n");

    // Arriving at the granary
    printf("You arrive at the granary and find it infested with rats. You draw your sword and prepare for battle.\n");

    // Fighting the rats
    int rats = 10;
    while (rats > 0)
    {
        int hits = rand() % 3 + 1;
        printf("You attack the rats and hit %d of them.\n", hits);
        rats -= hits;
    }

    // Reporting back to the villager
    printf("You return to the villager and report your success.\n");
    printf("Villager: Thank you, kind adventurer! We are in your debt.\n");

    return 0;
}