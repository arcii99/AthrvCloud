//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int internet_speed[5];
  int sum = 0, max_speed = 0, min_speed = 1000000000;
  float average;

  // Prompt the user to enter the internet speeds
  printf("Enter 5 internet speeds in Mbps:\n");
  for(int i=0; i<5; i++) {
    scanf("%d", &internet_speed[i]);
  }

  // Calculate the average speed, maximum speed and minimum speed
  for(int i=0; i<5; i++) {
    sum += internet_speed[i];
    if(internet_speed[i] > max_speed) {
      max_speed = internet_speed[i];
    }
    if(internet_speed[i] < min_speed) {
      min_speed = internet_speed[i];
    }
  }
  average = (float) sum / 5;

  // Display the results to the user
  printf("\nResults:\n");
  printf("Average speed: %.2f Mbps\n", average);
  printf("Maximum speed: %d Mbps\n", max_speed);
  printf("Minimum speed: %d Mbps\n", min_speed);

  // Randomly generate a number between 0 and 4
  srand(time(NULL));
  int random_index = rand() % 5;

  // Display the internet speed at the randomly generated index
  printf("\nYour internet speed at index %d is %d Mbps\n", random_index, internet_speed[random_index]);

  return 0;
}