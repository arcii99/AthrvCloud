//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void generateBaggage(int airport[][10]);
void printAirport(int airport[][10]);
void moveBags(int airport[][10]);
int isBagAtEndZone(int airport[][10], int r);

// main function
int main()
{
    int airport[5][10] = {0}; // 5 rows and 10 columns of arrays to simulate the airport baggage system

    // generate baggage randomly
    generateBaggage(airport);

    // print initial state of airport baggage system
    printf("Initial Airport Baggage System State:\n");
    printAirport(airport);

    // move bags towards the end zone (last row)
    moveBags(airport);

    // print final state of airport baggage system
    printf("\nFinal Airport Baggage System State:\n");
    printAirport(airport);

    return 0;
}

// function definitions

// generates random baggage for the airport
void generateBaggage(int airport[][10])
{
    int r, c;
    srand(time(NULL));
    for (r = 0; r < 5; r++)
    {
        for (c = 0; c < 10; c++)
        {
            airport[r][c] = rand() % 2; // randomly generates a 0 or 1 to indicate presence or absence of baggage
        }
    }
}

// prints the current state of the airport baggage system
void printAirport(int airport[][10])
{
    int r, c;
    for (r = 0; r < 5; r++)
    {
        for (c = 0; c < 10; c++)
        {
            printf("%d ", airport[r][c]);
        }
        printf("\n");
    }
}

// moves bags towards the end zone (last row)
void moveBags(int airport[][10])
{
    int r, c, flag = 0; // flag to check if the end zone is reached
    // continue moving bags until no bag is left to be moved towards the end zone
    while (!flag) 
    {
        flag = 1; // assume all bags have reached the end zone, check this in the next loop

        for (r = 0; r < 5; r++)
        {
            for (c = 0; c < 10; c++)
            {
                if (airport[r][c] == 1) // check if a bag is present at current cell
                {
                    if (isBagAtEndZone(airport, r)) // check if bag is already at end zone
                    {
                        airport[r][c] = 0; // remove the bag from the current cell
                    }
                    else // move bag towards the end zone (last row)
                    {
                        airport[r+1][c] = 1; // place the bag in the row below
                        airport[r][c] = 0; // remove the bag from the current cell
                        flag = 0; // set flag to 0 as at least one bag has not yet reached end zone
                    }
                }
            }
        }
    }
}

// checks if a bag is already at the end zone or last row of the airport baggage system
int isBagAtEndZone(int airport[][10], int r)
{
    int c;
    for (c = 0; c < 10; c++)
    {
        if (airport[r][c] == 1)
        {
            return 0; // return 0 if a bag is found in current row r, meaning it has not yet reached the end zone
        }
    }
    return 1; // return 1 if no bag is found in current row r, meaning all bags have reached the end zone
}