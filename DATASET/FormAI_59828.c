//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // initialize random number generator
    char player1[20], player2[20];
    int ships1, ships2;
    float odds1, odds2;

    // take input from player1
    printf("Enter name of player 1: ");
    scanf("%s", player1);
    printf("Enter expected number of alien ships for %s: ", player1);
    scanf("%d", &ships1);

    // take input from player2
    printf("Enter name of player 2: ");
    scanf("%s", player2);
    printf("Enter expected number of alien ships for %s: ", player2);
    scanf("%d", &ships2);

    // compute invasion probability for player1
    odds1 = ((float) ships1 / 100) * (rand() % 101);
    // compute invasion probability for player2
    odds2 = ((float) ships2 / 100) * (rand() % 101);

    // display results to players
    printf("\n%s's invasion probability is %.2f%%\n", player1, odds1);
    printf("%s's invasion probability is %.2f%%\n", player2, odds2);

    // create leaderboard
    if (odds1 > odds2)
    {
        printf("%s is more likely to be invaded\n", player1);
    }
    else if (odds2 > odds1)
    {
        printf("%s is more likely to be invaded\n", player2);
    }
    else
    {
        printf("Both players have the same probability of being invaded\n");
    }

    return 0;
}