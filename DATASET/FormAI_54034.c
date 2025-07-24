//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10    //Maximum number of cars on the road
#define MIN_DIST 5   //Minimum distance between cars in meters
#define MAX_V 80   //Maximum speed limit in kmph
#define LIGHT_TIME 10  //Time in seconds for a traffic light to turn red or green

int main() {
  srand(time(0));
  int speed[MAX]; 
  int position[MAX]; 
  int distance_to_next_car[MAX];
  int i, j, k, x;
  int timeElapsed; 
  int lightStatus = 1; //1 for green, 0 for red
  float avgSpeed;
  
  // initializing speeds and positions of cars
  for(i = 0; i < MAX ; i++) {
    speed[i] = (rand() % MAX_V) + 1;
    position[i] = i * 50;
  } 

  // print initial positions and speeds of all cars
  printf("Initial Positions and Speeds of Cars:\n");
  for(i = 0; i < MAX; i++)
    printf("Car#%d - Speed: %dkmph, Position: %dms \n", i+1, speed[i], position[i]);

  timeElapsed = 0; //Starting time of simulation

  // update positions of cars accordingly
  while(timeElapsed <= 300) { 
    for(i = 0; i < MAX; i++) { 
      distance_to_next_car[i] = 5000; 
      for(j = 0; j < MAX; j++) {
        if(i != j) {
          if(position[i] < position[j]) 
            distance_to_next_car[i] = position[j] - position[i]; 
        }
      } 

      if(distance_to_next_car[i] > MIN_DIST && speed[i] < MAX_V && lightStatus == 1)
        speed[i]++; 
      else if(distance_to_next_car[i] < MIN_DIST) {
        if(speed[i] > speed[j] && lightStatus == 1) {
          speed[i] = speed[j]; 
        }
        else
          speed[i]--; 
      }
      else if(lightStatus == 0) {
        speed[i]--;
      }
      position[i] += speed[i] / 3.6; 
    } 

    // status of traffic light
    if(timeElapsed % LIGHT_TIME == 0) {
      if(lightStatus == 1)
        lightStatus = 0;
      else
        lightStatus = 1;
    }

    // print status of cars at each second
    printf("\nTime: %ds\n", timeElapsed);
    for(i = 0; i < MAX; i++) {
      printf("Car#%d - Speed: %dkmph, Position: %dms\n", i+1, speed[i], position[i]);
      avgSpeed += speed[i];
    }

    avgSpeed = avgSpeed / MAX; //average speed of all cars
    printf("Average Speed of Cars: %.2f kmph\n", avgSpeed);

    timeElapsed++; 
  }

  return 0;
}