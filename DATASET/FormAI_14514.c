//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void turn_on_lights(int room) {
  printf("Turning on lights in room %d\n", room);
}

void turn_off_lights(int room) {
  printf("Turning off lights in room %d\n", room);
}

void recursive_automation(int rooms[], int num_rooms, int current_room) {
  if (current_room == num_rooms) { // Base case: all rooms have been checked
    return;
  }
  
  if (rooms[current_room] == 1) { // If lights are on, turn them off and move to next room
    turn_off_lights(current_room);
    recursive_automation(rooms, num_rooms, current_room+1);
  } else { // If lights are off, turn them on and recursively check all previous rooms
    turn_on_lights(current_room);
    int i;
    for (i = current_room-1; i >= 0; i--) { // Turn on all lights in previous rooms
      if (rooms[i] == 0) {
        turn_on_lights(i);
        rooms[i] = 1; // Set room as checked and lights as on
      }
    }
    recursive_automation(rooms, num_rooms, current_room+1);
  }
}

int main() {
  int num_rooms = 5;
  int rooms[] = {0, 0, 0, 1, 0};
  
  recursive_automation(rooms, num_rooms, 0);
  
  return 0;
}