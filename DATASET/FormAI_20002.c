//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to generate a random number
int random_number(int limit)
{
    int num = rand() % limit;
    return num;
}

int main()
{
    srand(time(NULL));

    // Conspiracy theories to choose from
    char *theories[] = {"The moon landing was faked",
                        "Aliens are among us",
                        "The Illuminati control the world",
                        "Chemtrails are real",
                        "The Earth is flat",
                        "The government is hiding the cure for cancer",
                        "The world will end in 2022",
                        "The Bermuda Triangle is a portal to another dimension",
                        "Bigfoot is real and the government is hiding it",
                        "9/11 was an inside job"};

    int num_theories = sizeof(theories) / sizeof(theories[0]);

    // Generate a random conspiracy theory
    int index = random_number(num_theories);
    char *theory = theories[index];

    // Print the theory
    printf("Did you know that %s?\n", theory);

    // Generate some "evidence"
    int evidence = random_number(100);

    // Print the "evidence"
    if (evidence < 50)
    {
        printf("And if you don't believe me, just look at all the 'coincidences'!\n");
    }
    else
    {
        printf("It's obvious when you connect the dots!\n");
    }

    // Generate a person or group responsible for the theory
    char *responsible[] = {"The government",
                             "The Illuminati",
                             "Big Pharma",
                             "Elon Musk",
                             "The New World Order",
                             "The lizard people"};

    int num_responsible = sizeof(responsible) / sizeof(responsible[0]);
    int resp_index = random_number(num_responsible);
    char *resp = responsible[resp_index];

    // Print the responsible party
    printf("%s is behind %s. Trust me, I've done the research!\n", resp, theory);

    // Print some random "facts"
    printf("Did you know that birds aren't real? They're actually government drones!\n");
    printf("The pyramids were actually built by aliens!\n");
    printf("The earth is hollow, and there's a civilization of giants living inside!\n");

    return 0;
}