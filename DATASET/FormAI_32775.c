//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>

// define constants
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// define structures
struct Elevator {
   int current_floor;   // current floor of elevator
   int destination;     // floor elevator is going to
   int is_moving;       // flag to indicate if elevator is moving
};

// function prototypes
void move_elevator(struct Elevator *elevator);
void print_elevator_status(struct Elevator *elevator);

int main(void) {
   struct Elevator elevators[NUM_ELEVATORS] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };  // initialize elevators
   int floors[NUM_FLOORS] = { 0 };                                                  // initialize floors

   // simulate people pressing elevator buttons on floors
   floors[3] = 1;   // someone on 4th floor wants to go up
   floors[7] = -1;  // someone on 8th floor wants to go down

   while (1) {  // infinite loop
      // move all elevators
      for (int i = 0; i < NUM_ELEVATORS; i++) {
         move_elevator(&elevators[i]);
      }

      // check if anyone is waiting for an elevator
      for (int i = 0; i < NUM_FLOORS; i++) {
         if (floors[i] != 0) {
            // find closest available elevator
            int closest_elevator = -1;  // index of closest available elevator
            int closest_dist = NUM_FLOORS;  // distance in floors to closest available elevator
            for (int j = 0; j < NUM_ELEVATORS; j++) {
               if (elevators[j].is_moving == 0 && abs(elevators[j].current_floor - i) < closest_dist) {
                  closest_elevator = j;
                  closest_dist = abs(elevators[j].current_floor - i);
               }
            }

            // assign closest available elevator to pick up person
            if (closest_elevator != -1) {
               elevators[closest_elevator].destination = i;
               if (i > elevators[closest_elevator].current_floor) {
                  elevators[closest_elevator].is_moving = 1;
               }
               else if (i < elevators[closest_elevator].current_floor) {
                  elevators[closest_elevator].is_moving = -1;
               }
               floors[i] = 0;  // reset button press
            }
         }
      }

      // print elevator status
      for (int i = 0; i < NUM_ELEVATORS; i++) {
         print_elevator_status(&elevators[i]);
      }
   }

   return 0;
}

// function to move elevator one floor
void move_elevator(struct Elevator *elevator) {
   if (elevator->is_moving != 0) {
      elevator->current_floor += elevator->is_moving;
      if (elevator->current_floor == elevator->destination) {
         elevator->is_moving = 0;
      }
   }
}

// function to print elevator status
void print_elevator_status(struct Elevator *elevator) {
   printf("Elevator on floor %d, ", elevator->current_floor);
   if (elevator->is_moving == 0) {
      printf("not moving.\n");
   }
   else if (elevator->is_moving == 1) {
      printf("going up.\n");
   }
   else {
      printf("going down.\n");
   }
}