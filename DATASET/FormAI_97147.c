//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: high level of detail
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

// Define the constants for the traffic lights
# define RED 0
# define YELLOW 1
# define GREEN 2

// Define the index positions for each light
# define NORTH_SOUTH 0
# define EAST_WEST 1

// Define the time intervals for each light
# define RED_LIGHT_TIME 10
# define YELLOW_LIGHT_TIME 3
# define GREEN_LIGHT_TIME 10

// Define the structure for traffic lights
typedef struct {
  int north_south;
  int east_west;
} TrafficLight;

// Define the function to generate random numbers
int random_number(int min_num, int max_num) {
  int result=0,low_num=0,hi_num=0;
  if(min_num<max_num) {
    low_num=min_num;
    hi_num=max_num+1;
  } 
  else {
    low_num=max_num+1;
    hi_num=min_num;
  }
  srand(time(NULL));
  result = (rand()%(hi_num-low_num))+low_num;
  return result;
}

int main() {
  // Declare the variables
  int red_timer = RED_LIGHT_TIME;
  int yellow_timer = YELLOW_LIGHT_TIME;
  int green_timer = GREEN_LIGHT_TIME;
  TrafficLight lights[2];
  lights[NORTH_SOUTH].east_west = RED;
  lights[NORTH_SOUTH].north_south = GREEN;
  lights[EAST_WEST].north_south = RED;
  lights[EAST_WEST].east_west = GREEN;
  
  // While loop for traffic control simulation
  while (1) {
    // Decrement the timer for current light
    if (lights[EAST_WEST].east_west == RED) {
      yellow_timer--;
      if (yellow_timer == 0) {
        yellow_timer = YELLOW_LIGHT_TIME;
        lights[EAST_WEST].east_west = GREEN;
        lights[EAST_WEST].north_south = RED;
        lights[NORTH_SOUTH].north_south = YELLOW;
      }
    } 
    else if (lights[NORTH_SOUTH].north_south == RED) {
      yellow_timer--;
      if (yellow_timer == 0) {
        yellow_timer = YELLOW_LIGHT_TIME;
        lights[NORTH_SOUTH].north_south = GREEN;
        lights[NORTH_SOUTH].east_west = RED;
        lights[EAST_WEST].east_west = YELLOW;
      }
    }
    else if (lights[NORTH_SOUTH].north_south == YELLOW) {
      green_timer--;
      if (green_timer == 0) {
        green_timer = GREEN_LIGHT_TIME;
        lights[NORTH_SOUTH].north_south = RED;
        lights[NORTH_SOUTH].east_west = GREEN;
      }
    }
    else if (lights[EAST_WEST].east_west == YELLOW){
      green_timer--;
      if (green_timer == 0) {
        green_timer = GREEN_LIGHT_TIME;
        lights[EAST_WEST].east_west = RED;
        lights[EAST_WEST].north_south = GREEN;
      }
    }
    // Print the current status of the traffic lights
    printf("North-South: %d, East-West: %d\n", lights[NORTH_SOUTH].north_south, lights[NORTH_SOUTH].east_west);
    printf("East-West: %d, North-South: %d\n", lights[EAST_WEST].east_west, lights[EAST_WEST].north_south);
    // Wait for a random amount of time (1-4 seconds) before switching lights
    int wait_time = random_number(1, 4);
    printf("Waiting for %d seconds...\n", wait_time);
    for (int i = 0; i < wait_time; i++) {
      printf("%d...\n", wait_time-i);
      sleep(1);
    }
  }
  return 0;
}