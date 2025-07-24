//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Set up remote control
  int remote_id = 1234;
  int channel_no = 3;

  // Connect to drone
  int drone_id = 5678;
  int drone_channel = 6;

  printf("Connecting to drone...\n");

  // Check connection
  if(remote_id == drone_id) {
    if(channel_no == drone_channel) {
      printf("Connected to drone on channel %d\n", drone_channel);
    }
    else {
      printf("Drone is not on correct channel.\n");
    }
  }
  else {
    printf("Unable to connect to drone.\n");
    exit(1);
  }

  // Send commands to drone
  printf("Enter a command to send to the drone: ");
  char command[50];
  scanf("%s", command);

  // Execute command
  if(strcmp(command, "takeoff") == 0) {
    printf("Drone taking off!\n");
  }
  else if(strcmp(command, "land") == 0) {
    printf("Drone landing!\n");
  }
  else if(strcmp(command, "left") == 0) {
    printf("Drone moving left!\n");
  }
  else if(strcmp(command, "right") == 0) {
    printf("Drone moving right!\n");
  }
  else if(strcmp(command, "forward") == 0) {
    printf("Drone moving forward!\n");
  }
  else if(strcmp(command, "back") == 0) {
    printf("Drone moving back!\n");
  }
  else {
    printf("Unknown command.\n");
  }

  return 0;
}