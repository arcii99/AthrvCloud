//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BAGS 50
#define CONVEYOR_CAPACITY 10

int main()
{
    int bags_in_conveyor = 0;
    int bags_picked = 0;
    int bags_transferred = 0;
    int bags_lost = 0;
    int bags_arrived = 0;
    int conveyors_active = 1; // Initially, conveyor 1 is active

    printf("Starting Airport Baggage Handling Simulation\n");

    for(int i = 1; i <= BAGS; i++){

        int random_num = rand() % 10 + 1; // Random number between 1 and 10

        if(random_num <= 7){ // If number is from 1 to 7, add bag to the conveyor

            bags_in_conveyor++;

            printf("\nBag %d has arrived on the conveyor %d\n", i, conveyors_active);

            if(bags_in_conveyor == CONVEYOR_CAPACITY){ // If capacity has been reached, transfer bags to the next conveyor
                
                bags_transferred += bags_in_conveyor;
                bags_in_conveyor = 0;

                if(conveyors_active == 1){ // If we were on conveyor 1, switch to conveyor 2
                    conveyors_active = 2;
                }
                else{ // If we were on conveyor 2, switch to conveyor 1
                    conveyors_active = 1;
                }
                
                printf("\n%d bags have been transfered from conveyor %d to conveyor %d\n", CONVEYOR_CAPACITY, conveyors_active == 2 ? 1 : 2, conveyors_active);
            }
        }
        else{ // If number is from 8 to 10, lose the bag
            bags_lost++;
            printf("\nBag %d was lost in the transfer\n", i);
        }
    }

    printf("\nSimulation complete!\n\n");

    bags_arrived = BAGS - bags_lost;

    printf("\nTotal number of bags that arrived: %d\n", bags_arrived);
    printf("Total number of bags that were picked up: %d\n", bags_picked);
    printf("Total number of bags that were transferred: %d\n", bags_transferred);
    printf("Total number of bags that were lost: %d\n", bags_lost);

    return 0;
}