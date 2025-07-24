//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SPEED 1 // minimum internet speed in megabits per second
#define MAX_SPEED 100 // maximum internet speed in megabits per second

#define NUM_PLAYERS 4 // number of players in the game

// function prototypes
int getRandomSpeed(); // generates a random internet speed
int getAvgSpeed(int[]); // calculates the average internet speed
int getWinner(int[]); // determines the winner of the game

int main()
{
    // initialize array of speeds
    int speeds[NUM_PLAYERS] = {0};

    // generate random speeds for each player
    srand(time(NULL));
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        speeds[i] = getRandomSpeed();
    }

    // display the speeds
    printf("Internet Speeds (in megabits per second)\n");
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Player %d: %d\n", i+1, speeds[i]);
    }
    printf("\n");

    // calculate and display the average speed
    int avgSpeed = getAvgSpeed(speeds);
    printf("Average Speed: %d\n\n", avgSpeed);

    // determine the winner and display the results
    int winner = getWinner(speeds);
    printf("Player %d wins!\n", winner+1);

    return 0;
}

// generates a random internet speed between MIN_SPEED and MAX_SPEED
int getRandomSpeed()
{
    return (rand() % (MAX_SPEED-MIN_SPEED+1)) + MIN_SPEED;
}

// calculates the average internet speed
int getAvgSpeed(int speeds[])
{
    int sum = 0;
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        sum += speeds[i];
    }
    return sum / NUM_PLAYERS;
}

// determines the winner of the game
int getWinner(int speeds[])
{
    int maxSpeed = speeds[0];
    int winner = 0;
    for (int i = 1; i < NUM_PLAYERS; i++)
    {
        if (speeds[i] > maxSpeed)
        {
            maxSpeed = speeds[i];
            winner = i;
        }
    }
    return winner;
}