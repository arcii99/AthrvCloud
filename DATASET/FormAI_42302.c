//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Global variables - road, traffic light, cars
int road[10]; // represents the road with 10 blocks/cells
int traffic_light = 0; // 0 stands for green, 1 for red
char* cars[5] = {"Romeo", "Juliet", "Mercutio", "Benvolio", "Tybalt"}; // list of cars participating in the traffic

// function to randomly select two cars
void select_cars(int* car1, int* car2) {
  *car1 = rand() % 5;
  *car2 = rand() % 5;
  while (*car1 == *car2) { // checks if both are same
    *car2 = rand() % 5;
  }
}

// function to check if the traffic light is green or red
int is_green() {
  return traffic_light == 0;
}

// function to move a car to the next block
void move_car(int car) {
  for (int i = 0; i < 9; i++) { // update the road and move
    if (road[i] == car) {
      road[i] = 0;
      road[i+1] = car;
      break;
    }
  }
}

// main function that simulates the traffic flow
int main() {
  
  // initialize the road with no cars
  for (int i = 0; i < 10; i++) {
    road[i] = 0;
  }
  
  // randomize the seed for selecting two cars
  srand(time(0));
  
  // infinite loop to simulate traffic
  while (1) {
    
    // check if the traffic light is green
    if (is_green()) {
      
      // select two cars for traffic
      int car1, car2;
      select_cars(&car1, &car2);
      
      // move car 1 to the next block
      move_car(car1+1);
      
      // check if car 1 has crossed the road
      if (road[9] == car1+1) {
        printf("%s has crossed the road\n", cars[car1]);
        break; // exit infinite loop
      }
      
      // move car 2 to the next block
      move_car(car2+1);
      
      // check if car 2 has crossed the road
      if (road[9] == car2+1) {
        printf("%s has crossed the road\n", cars[car2]);
        break; // exit infinite loop
      }
      
    }
    
    // toggle the traffic light after each iteration
    traffic_light = 1 - traffic_light;
    
  }
  
  return 0; // end of program

}