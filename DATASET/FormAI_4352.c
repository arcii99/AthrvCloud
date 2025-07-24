//FormAI DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>

// Define the states of the devices
#define OFF 0
#define ON 1

// Define the maximum number of devices in the home
#define MAX_DEVICES 10

// Define the maximum number of rooms in the home
#define MAX_ROOMS 5

int main() {
  // Set up the random seed
  srand(time(NULL));
  
  // Create an array to store the state of each device
  int devices[MAX_DEVICES];
  
  // Initialize all devices to the off state
  for(int i = 0; i < MAX_DEVICES; i++) {
    devices[i] = OFF;
  }
  
  // Create an array to store the devices in each room
  int rooms[MAX_ROOMS][MAX_DEVICES];
  
  // Assign devices to rooms randomly
  for(int i = 0; i < MAX_ROOMS; i++) {
    for(int j = 0; j < MAX_DEVICES; j++) {
      rooms[i][j] = rand() % 2;
    }
  }
  
  // Create a variable to keep track of the current room
  int current_room = rand() % MAX_ROOMS;
  
  // Start the loop that will run the program until
  // all devices are off in all rooms
  bool run_program = true;
  while(run_program) {
    // Turn off all devices in all rooms
    for(int i = 0; i < MAX_ROOMS; i++) {
      for(int j = 0; j < MAX_DEVICES; j++) {
        if(rooms[i][j] == ON) {
          devices[j] = OFF;
        }
      }
    }
    
    // Randomly turn on devices in the current room
    for(int i = 0; i < MAX_DEVICES; i++) {
      if(rooms[current_room][i] == ON && rand() % 2 == 0) {
        devices[i] = ON;
      }
    }
    
    // Print the status of all devices in all rooms
    printf("Room %d:\n", current_room + 1);
    for(int i = 0; i < MAX_DEVICES; i++) {
      if(rooms[current_room][i] == ON) {
        printf("Device %d is %s\n", i + 1, devices[i] == ON ? "on" : "off");
      }
    }
    
    // Check if all devices are off in all rooms
    bool all_off = true;
    for(int i = 0; i < MAX_ROOMS; i++) {
      for(int j = 0; j < MAX_DEVICES; j++) {
        if(devices[j] == ON && rooms[i][j] == ON) {
          all_off = false;
        }
      }
    }
    
    // If all devices are off in all rooms, the program ends
    if(all_off) {
      run_program = false;
    }
    // Otherwise, change the current room randomly
    else {
      current_room = rand() % MAX_ROOMS;
    }
  }
  
  // End of program
  return 0;
}