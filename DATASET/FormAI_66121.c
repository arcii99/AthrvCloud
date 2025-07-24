//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Airport Baggage Handling Simulation Program\n");

    int numOfPassengers, numOfBags;
    srand(time(0)); //seed for random number generator
    
    printf("Please enter the number of passengers:\n");
    scanf("%d", &numOfPassengers);

    printf("Please enter the number of bags for each passenger:\n");
    scanf("%d", &numOfBags);

    int totalBags = numOfPassengers * numOfBags;
    printf("Total number of bags to be handled: %d\n", totalBags);

    //Let's simulate the baggage handling process
    int handledBags = 0;
    int lostBags = 0;

    for(int i=0; i<numOfPassengers; i++)
    {
        for(int j=0; j<numOfBags; j++)
        {
            int prob = rand() % 100; //generating a random probability

            if(prob < 10) //10% probability of a bag getting lost
            {
                printf("Bag lost for Passenger %d, Bag No %d\n", i+1, j+1);
                lostBags++;
            }
            else //90% probability of successful handling
            {
                printf("Passenger %d, Bag No %d handled successfully\n", i+1, j+1);
                handledBags++;
            }
        }
    }

    printf("\nTotal bags handled: %d\n", handledBags);
    printf("Total bags lost: %d\n", lostBags);

    return 0;
}