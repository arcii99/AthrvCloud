//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10 //number of floors in the building
#define ELEVATORS 3 //number of elevators in the building

int floors[FLOORS]; //1 means someone is waiting for the elevator, 0 means no one is waiting
int elevators[ELEVATORS]; //current floor number of each elevator
int direction[ELEVATORS]; //1 means going up, -1 means going down, 0 means stationary

int main()
{
    int i, j, k;
    int tick = 0; //time elapsed since program started
    int passengers = 0; //total number of passengers served by elevators
    int max_passengers = 0; //maximum number of passengers in any elevator at any time
    srand(time(NULL)); //seed random number generator
    
    //initialize elevators to random floors and directions
    for(i=0; i<ELEVATORS; i++)
    {
        elevators[i] = rand() % FLOORS;
        if(elevators[i] == 0)
            direction[i] = 1;
        else if(elevators[i] == FLOORS-1)
            direction[i] = -1;
        else
            direction[i] = (rand() % 2 == 0) ? 1 : -1;
    }
    
    //main loop
    while(1)
    {
        //update floors array based on passenger arrivals
        for(i=0; i<FLOORS; i++)
        {
            if(rand() % 10 == 0) //1 in 10 chance of someone arriving on floor i
                floors[i] = 1;
        }
        
        //update elevators array based on passenger departures and arrivals
        for(i=0; i<ELEVATORS; i++)
        {
            if(direction[i] == 1) //going up
            {
                if(elevators[i] == FLOORS-1) //reached top floor, switch direction
                    direction[i] = -1;
                else if(floors[elevators[i]+1] == 1) //passenger wants to go up
                {
                    passengers++;
                    elevators[i]++;
                    floors[elevators[i]] = 0;
                }
                else if(floors[elevators[i]] == 1) //passenger wants to get off here
                {
                    passengers++;
                    floors[elevators[i]] = 0;
                }
                else //continue going up
                    elevators[i]++;
            }
            else if(direction[i] == -1) //going down
            {
                if(elevators[i] == 0) //reached bottom floor, switch direction
                    direction[i] = 1;
                else if(floors[elevators[i]-1] == 1) //passenger wants to go down
                {
                    passengers++;
                    elevators[i]--;
                    floors[elevators[i]] = 0;
                }
                else if(floors[elevators[i]] == 1) //passenger wants to get off here
                {
                    passengers++;
                    floors[elevators[i]] = 0;
                }
                else //continue going down
                    elevators[i]--;
            }
            
            //update max_passengers variable
            if(passengers > max_passengers)
                max_passengers = passengers;
        }
        
        //print current floor for each elevator
        printf("Tick %d\n", tick);
        for(i=0; i<ELEVATORS; i++)
            printf("Elevator %d is on floor %d, going %s\n", i+1, elevators[i]+1, (direction[i] == 1) ? "up" : ((direction[i] == -1) ? "down" : "stationary"));
        printf("Total passengers served: %d\n", passengers);
        printf("Max passengers in one elevator: %d\n", max_passengers);
        printf("\n");
        
        tick++; //increment time
    }
    
    return 0;
}