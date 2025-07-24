//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include<stdio.h>

int main() {
  int car_count = 0;
  int green_light_time = 10;
  int yellow_light_time = 5;
  int red_light_time = 15;
  int current_light_time = green_light_time;
  char input;

  printf("Welcome to the Traffic Light Controller Simulator!\n");

  while(1) {
    printf("\nPress c to add a car, q to exit: ");
    scanf(" %c", &input);
    
    if(input == 'c') {
      car_count++;
      printf("Added one car, total: %d\n", car_count);
    }
    else if(input == 'q') {
      printf("Exiting the program...\n");
      break;
    }
    else {
      printf("Invalid input, try again.\n");
    }

    if(car_count % 10 == 0 && car_count != 0) {
      printf("10 cars reached, changing to yellow light for %d seconds.\n", yellow_light_time);
      current_light_time = yellow_light_time;
    }
    else if(current_light_time == green_light_time) {
      printf("Green light for %d seconds.\n", green_light_time);
    }
    else if(current_light_time == yellow_light_time) {
      printf("Yellow light for %d seconds.\n", yellow_light_time);
      current_light_time = red_light_time;
    }
    else {
      printf("Red light for %d seconds.\n", red_light_time);
      current_light_time = green_light_time;
    }
  }

  return 0;
}