//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
/* This program is a Traffic Light Controller that allows pedestrians to cross the road safely. */
#include<stdio.h>

int main() {
  int green_light_time = 10; // Duration of green light
  int red_light_time = 5; // Duration of red light
  int pedestrian_time = 7; // Duration of pedestrian light
  int signal = 0; // Traffic signal status (0 = Red, 1 = Green)
  int pedestrian_signal = 0; // Pedestrian signal status (0 = Red, 1 = Green)

  while (1) { // Loop indefinitely
    if (signal == 0) { // If signal is red
      printf("Signal is Red\n");
      printf("Pedestrians can cross safely for %d seconds\n", pedestrian_time);
      pedestrian_signal = 1; // Turn pedestrian signal green
      while (pedestrian_time >= 0) { // For pedestrian signal duration
        printf("Pedestrian signal is Green for %d seconds\n", pedestrian_time);
        pedestrian_time--;
        if (pedestrian_time == 0) pedestrian_signal = 0; // Turn pedestrian signal red
      }
      printf("Pedestrians cannot cross anymore\n");
      signal = 1; // Turn traffic signal green
    } else { // If signal is green
      printf("Signal is Green\n");
      printf("Cars can pass through safely for %d seconds\n", green_light_time);
      while (green_light_time >= 0) { // For green signal duration
        printf("Traffic signal is Green for %d seconds\n", green_light_time);
        green_light_time--;
        if (green_light_time == 0) signal = 0; // Turn traffic signal red
      }
    }
  }
  return 0;
}