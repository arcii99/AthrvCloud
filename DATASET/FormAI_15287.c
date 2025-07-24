//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char conspiracy[5][100] = {
        "The moon landing was faked by the government",
        "Elvis Presley is still alive and living in a bunker",
        "Chemtrails are being used to control people's minds",
        "The Illuminati controls the world's governments",
        "The earth is flat and the government is hiding it"
    };
    char action[5][100] = {
        "is planning to",
        "has been",
        "has dedicated his life to",
        "has an agenda to",
        "is secretly working on"
    };
    char goal[5][100] = {
        "rule the world",
        "create a new world order",
        "suppress the truth",
        "enforce their beliefs",
        "maintain their power"
    };
    char evidence[5][100] = {
        "For example, just look at the lack of stars in the moon landing footage.",
        "The fact that there have been more sightings of Elvis since his supposed death than before is suspicious.",
        "People who have been exposed to chemtrails report feelings of confusion and memory loss.",
        "Symbols associated with the Illuminati can be found in many government and corporate logos.",
        "The horizon always appears flat, regardless of altitude or distance."
    };
    int rand_conspiracy = rand() % 5;
    int rand_action = rand() % 5;
    int rand_goal = rand() % 5;
    int rand_evidence = rand() % 5;

    printf("Did you know that %s %s %s? %s\n", conspiracy[rand_conspiracy], action[rand_action], goal[rand_goal], evidence[rand_evidence]);

    return 0;
}