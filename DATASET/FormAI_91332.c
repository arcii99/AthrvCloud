//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: statistical
#include<stdio.h>

//Declare some macros for the program
#define TRUE 1
#define FALSE 0
#define MAX_FLOORS 10
#define MIN_FLOORS 1

//Declare gloabal variables for the simulation
int current_floor = 1;   //represents the floor the elevator is currently on
int target_floor = 1;    //represents the destination floor of the elevator
int passengers = 0;      //represents the number of passengers in the elevator
int direction = 0;       //represents the direction the elevator is currently moving in
int floors_passed = 0;   //represents the number of floors the elevator has passed
int time_elapsed = 0;    //represents the tital time elapsed in the simulation

//Declare functions for the main program
void MoveElevator();
void UpdateStats();

int main()
{
  //initialize all variables to their starting values
  current_floor = 1;
  target_floor = 1;
  passengers = 0;
  direction = 0;
  floors_passed = 0;
  time_elapsed = 0;

  //set a flag to true to indicate that the simulation is running
  int simulation_running = TRUE;

  //main simulation loop
  while(simulation_running)
  {
    //check if there are passengers in the elevator and if they have reached their destination floor
    if(passengers > 0 && current_floor == target_floor)
    {
      //call the updatestats function to update the statistics for the simulation
      UpdateStats();

      //set the target floor back to 1 and determine the direction of the elevator
      target_floor = 1;
      if(direction == 1)
      {
        direction = -1;
      }
      else
      {
        direction = 1;
      }
    }

    //check if the elevator has reached a floor where passengers are waiting
    if(current_floor % 2 == 0 && passengers < 10)
    {
      //pick up a passenger and set their destination floor to a random floor between the current floor and the top floor of the building
      int destination = (rand() % (MAX_FLOORS - current_floor + 1)) + current_floor;
      passengers++;
      target_floor = destination;
    }

    //call the moveelevator function to move the elevator and calculate the time elapsed
    MoveElevator();
    time_elapsed++;

    //check if the elevator has reached the top floor and if all passengers have been dropped off
    if(current_floor == MAX_FLOORS && passengers == 0)
    {
      //end the simulation loop and print out the statistics for the simulation
      simulation_running = FALSE;

      printf("Elevator Simulation Complete!\n");
      printf("Time Elapsed: %d\n", time_elapsed);
      printf("Floors Passed: %d\n", floors_passed);
    }
  }

  return 0;
}

//Function to move the elevator
void MoveElevator()
{
  //check if the elevator is on the first or last floor and change direction accordingly
  if(current_floor == MIN_FLOORS)
  {
    direction = 1;
  }
  else if(current_floor == MAX_FLOORS)
  {
    direction = -1;
  }

  //add the direction to the current floor to determine the new floor the elevator will move to
  current_floor += direction;
  floors_passed++;
}

//Function to update the statistics for the simulation
void UpdateStats()
{
  printf("Passenger Dropped Off at Floor %d\n", target_floor);
  passengers--;
  if(passengers == 0)
  {
    printf("All Passengers Dropped Off\n");
  }
}