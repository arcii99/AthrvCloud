//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 10 // Number of floors in the building
#define ELEVATORS 2 // Number of elevators in the building
#define MAX_PASSENGERS 10 // Maximum number of passengers in the elevator

typedef struct {
   int destination;
   int in_elevator;
} passenger_t;

typedef struct {
   int current_floor;
   int destination;
   passenger_t passengers[MAX_PASSENGERS];
   int num_passengers;
} elevator_t;

int main() {
   int i, j;
   elevator_t elevators[ELEVATORS];
   int waiting[FLOORS] = { 0 };
   int time = 0;
   int idle_time[ELEVATORS] = { 0 };
   
   // initialize elevators and passengers
   for (i = 0; i < ELEVATORS; i++) {
      elevators[i].current_floor = 1;
      elevators[i].destination = 1;
      elevators[i].num_passengers = 0;
      for (j = 0; j < MAX_PASSENGERS; j++) {
         elevators[i].passengers[j].destination = 0;
         elevators[i].passengers[j].in_elevator = 0;
      }
   }
   
   // simulate the elevator system
   while (1) {
      // check if any passengers are waiting
      for (i = 0; i < FLOORS; i++) {
         if (waiting[i] > 0) {
            printf("Passengers waiting on floor %d\n", i+1);
         }
      }
      
      // check if any elevators are idle
      for (i = 0; i < ELEVATORS; i++) {
         if (elevators[i].current_floor == elevators[i].destination) {
            if (elevators[i].num_passengers == 0) {
               idle_time[i]++;
               printf("Elevator %d idle for %d minutes\n", i+1, idle_time[i]);
            }
            else {
               printf("Elevator %d stopped at floor %d\n", i+1, elevators[i].current_floor);
            }
         }
      }
      
      // move elevators and passengers
      for (i = 0; i < ELEVATORS; i++) {
         if (elevators[i].current_floor == elevators[i].destination) {
            // elevator is stopped
            if (elevators[i].num_passengers > 0) {
               // elevator has passengers, drop them off
               printf("Elevator %d stops at floor %d to drop off passengers\n", i+1, elevators[i].current_floor);
               for (j = 0; j < elevators[i].num_passengers; j++) {
                  if (elevators[i].passengers[j].destination == elevators[i].current_floor) {
                     waiting[elevators[i].current_floor-1]++;
                     elevators[i].passengers[j].in_elevator = 0;
                     printf("Passenger %d has arrived at their destination on floor %d\n", j+1, elevators[i].current_floor);
                  }
               }
               elevators[i].num_passengers = 0;
            }
            else if (waiting[elevators[i].current_floor-1] > 0) {
               // elevator is empty, load waiting passengers
               printf("Elevator %d stops at floor %d to pick up passengers\n", i+1, elevators[i].current_floor);
               elevators[i].num_passengers = waiting[elevators[i].current_floor-1];
               waiting[elevators[i].current_floor-1] = 0;
               for (j = 0; j < elevators[i].num_passengers; j++) {
                  elevators[i].passengers[j].destination = rand() % FLOORS + 1;
                  elevators[i].passengers[j].in_elevator = 1;
                  printf("Passenger %d enters elevator %d, destination floor %d\n", j+1, i+1, elevators[i].passengers[j].destination);
               }
               elevators[i].destination = elevators[i].passengers[0].destination;
            }
            else {
               // elevator is empty and no passengers are waiting, keep going
               if (elevators[i].destination == FLOORS) {
                  elevators[i].destination = 1;
               }
               else {
                  elevators[i].destination++;
               }
               printf("Elevator %d continues to floor %d\n", i+1, elevators[i].destination);
            }
         }
         else {
            // elevator is moving
            if (elevators[i].destination > elevators[i].current_floor) {
               elevators[i].current_floor++;
               printf("Elevator %d moves up to floor %d\n", i+1, elevators[i].current_floor);
            }
            else {
               elevators[i].current_floor--;
               printf("Elevator %d moves down to floor %d\n", i+1, elevators[i].current_floor);
            }
         }
      }
      
      time++;
      if (time == 1440) break; // maximum simulation time of 24 hours
   }
   
   return 0;
}