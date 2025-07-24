//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

struct Elevator {
  int curr_floor;
  bool is_busy;
};

int main() {
  //initialize elevators
  struct Elevator elevators[NUM_ELEVATORS];
  for(int i = 0; i < NUM_ELEVATORS; i++) {
    elevators[i].curr_floor = 0;
    elevators[i].is_busy = false;
  }

  //initialize floor button press array
  bool floor_press[NUM_FLOORS];
  for(int i = 0; i < NUM_FLOORS; i++) {
    floor_press[i] = false;
  }

  //initialize loop variables
  int curr_time = 0;
  bool elev_moving = false;

  //start simulation loop
  while(true) {
    printf("Current Time: %d\n", curr_time);

    //check if any floor buttons are pressed
    bool floor_pressed = false;
    for(int i = 0; i < NUM_FLOORS; i++) {
      if(floor_press[i]) {
        floor_pressed = true;
        break;
      }
    }

    //if a floor button is pressed, find closest available elevator
    if(floor_pressed) {
      int closest_elev = -1;
      int min_dist = NUM_FLOORS + 1;
      for(int i = 0; i < NUM_ELEVATORS; i++) {
        if(!elevators[i].is_busy) {
          int dist = abs(elevators[i].curr_floor - i);
          if(dist < min_dist) {
            min_dist = dist;
            closest_elev = i;
          }
        }
      }
      
      if(closest_elev != -1) {
        elev_moving = true;
        elevators[closest_elev].is_busy = true;
        printf("Elevator %d has been dispatched to floor with button press\n", closest_elev+1);
      }
      else {
        printf("No elevators available to service floor buttons\n");
      }
    }
    else {
      printf("No floor buttons pressed\n");
    }

    //if an elevator is moving, update its position
    if(elev_moving) {
      for(int i = 0; i < NUM_ELEVATORS; i++) {
        if(elevators[i].is_busy) {
          int dest_floor = -1;
          for(int j = elevators[i].curr_floor + 1; j < NUM_FLOORS; j++) {
            if(floor_press[j]) {
              dest_floor = j;
              break;
            }
          }

          if(dest_floor == -1) {
            for(int j = elevators[i].curr_floor - 1; j >= 0; j--) {
              if(floor_press[j]) {
                dest_floor = j;
                break;
              }
            }
          }

          if(dest_floor == -1) {
            elev_moving = false;
            elevators[i].is_busy = false;
            printf("Elevator %d has finished all assigned tasks and is now available\n", i+1);
          }
          else if(dest_floor < elevators[i].curr_floor) {
            printf("Elevator %d going down to floor %d\n", i+1, dest_floor+1);
            elevators[i].curr_floor = dest_floor;
          }
          else {
            printf("Elevator %d going up to floor %d\n", i+1, dest_floor+1);
            elevators[i].curr_floor = dest_floor;
          }

          floor_press[elevators[i].curr_floor] = false;
        }
      }
    }
    else {
      printf("No elevators are currently in motion\n");
    }

    //update time and print separator
    curr_time++;
    printf("--------------------------------------------------\n");
  }
  
  return 0;
}