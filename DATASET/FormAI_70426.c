//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#define MAX 5 // Maximum floors
#define FLOOR_TIME 2 // Time taken for elevator to travel between floors
#define DOOR_TIME 3 // Time taken for door to open and close
#define MOVING_TIME 1 // Time taken for elevator to move up/down
#define IDLE_TIME 10 // Time taken for elevator to wait for a passenger

// Function to move the elevator up/down
void move(int curr_floor, int floor)
{
    int i;
    printf("Elevator is moving ");
    if(curr_floor<floor)
    {
        for(i=curr_floor;i<=floor;i++)
        {
            printf("%d ",i);
            sleep(MOVING_TIME);
        }
    }
    else if(curr_floor>floor)
    {
        for(i=curr_floor;i>=floor;i--)
        {
            printf("%d ",i);
            sleep(MOVING_TIME);
        }
    }
}

// Function to open/close the door
void door(int floor)
{
    printf("\nElevator has reached floor %d\n",floor);
    printf("Opening door...\n");
    sleep(DOOR_TIME);
    printf("Closing door...\n");
    sleep(DOOR_TIME);
}

int main()
{
    int curr_floor=1,dest_floor,passenger_count=0,i;
    int passenger[MAX]={0}; // To store the destination floors of passengers
    while(1) // Continuous loop for elevator operation
    {
        printf("Elevator is idle at floor %d\n",curr_floor);
        for(i=0;i<MAX;i++) // Check for passengers at each floor
        {
            if(passenger[i]!=0 && passenger[i]!=curr_floor) // If there is a passenger at a different floor
            {
                dest_floor=passenger[i];
                move(curr_floor,dest_floor); // Move the elevator to the passenger's floor
                curr_floor=dest_floor;
                door(curr_floor); // Open and close the door
                printf("Passenger 1 has been dropped off at floor %d\n",curr_floor);
                passenger[i]=0; // Remove the passenger from the list
                passenger_count--; // Decrease the passenger count
                sleep(IDLE_TIME); // Elevator waits for a defined time before moving again
            }
        }
        while(passenger_count<MAX) // While there is still space for passengers
        {
            for(i=0;i<MAX;i++) // Check for passengers at each floor
            {
                if(passenger[i]==0) // If there is no passenger at the floor
                {
                    printf("Elevator is idle at floor %d\n",curr_floor);
                    printf("Passenger %d is getting on the elevator at floor %d\n",passenger_count+1,i+1);
                    passenger[i]=rand()%MAX+1; // Randomly generate the destination floor
                    passenger_count++; // Increase the passenger count
                    printf("Passenger %d is going to floor %d\n",passenger_count,passenger[i]);
                    if(passenger_count==MAX) // If the elevator is full, break the loop
                        break;
                }
            }
            if(passenger_count==MAX) // If the elevator is full, break the loop
                break;
            printf("Elevator is idle at floor %d\n",curr_floor);
            printf("No passengers found. Elevator is idle...\n");
            sleep(IDLE_TIME); // Elevator waits for a defined time before checking for passengers again
        }
        dest_floor=1; // Default destination floor
        for(i=0;i<MAX;i++) // Iterate through the destination floors of passengers
        {
            if(passenger[i]!=0 && abs(curr_floor-passenger[i])<abs(curr_floor-dest_floor)) // If the passenger is going in the same direction as the elevator and is closer to the current floor
            {
                dest_floor=passenger[i];
            }
        }
        move(curr_floor,dest_floor); // Move the elevator to the closest passenger's floor
        curr_floor=dest_floor;
        door(curr_floor); // Open and close the door
        printf("Passenger 1 has been dropped off at floor %d\n",curr_floor);
        passenger[0]=0; // Remove the passenger from the list
        passenger_count--; // Decrease the passenger count
        sleep(IDLE_TIME); // Elevator waits for a defined time before checking for passengers again
    }
    return 0;
}