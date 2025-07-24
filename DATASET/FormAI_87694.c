//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int destination_x, destination_y, current_x, current_y, counter;
  float distance, speed, time_left;
  char direction;
  srand(time(NULL)); //seed random number generator
  
  //set destination coordinates
  destination_x = rand() % 100; //generate a random number between 0-99
  destination_y = rand() % 100;
  
  //initialize current coordinates to (0,0)
  current_x = 0;
  current_y = 0;
  
  printf("Welcome to RetroGPS Navigation Simulator!\n");
  printf("Your current location is (%d,%d)\n", current_x, current_y);
  printf("Your destination is (%d,%d)\n", destination_x, destination_y);

  while (current_x != destination_x || current_y != destination_y) { //while not at destination
    distance = sqrt(pow(destination_x-current_x,2)+pow(destination_y-current_y,2)); //calculate distance to destination
    speed = (rand() % 51) + 50; //generate random speed between 50-100
    time_left = distance / speed; //calculate time left to reach destination
    printf("You are %0.2f miles away from your destination\n", distance);
    printf("You are currently traveling at %0.2f miles per hour\n", speed);
    printf("You have %0.2f hours left to reach your destination\n", time_left);
    printf("Enter a direction (N,S,E,W): ");
    scanf(" %c", &direction); //get direction from user
    switch (direction) {
      case 'N':
        current_y++;
        break;
      case 'S':
        current_y--;
        break;
      case 'E':
        current_x++;
        break;
      case 'W':
        current_x--;
        break;
      default:
        printf("Invalid Direction!\n");
    }
    counter++; //increment counter to keep track of total moves
  }
  
  printf("\nCongratulations! You have reached your destination in %d moves!", counter);
  
  return 0;
}