//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>

int main() {
  int traffic_density, num_lanes, traffic_speed, length_road;
  float delay_per_vehicle, total_delay = 0;

  // Read input values
  printf("Enter Traffic Density (vehicles/km): ");
  scanf("%d", &traffic_density);
  printf("Enter Number of Lanes (1-3): ");
  scanf("%d", &num_lanes);
  printf("Enter Traffic Speed (km/h): ");
  scanf("%d", &traffic_speed);
  printf("Enter Length of Road (km): ");
  scanf("%d", &length_road);

  // Calculate delay per vehicle
  delay_per_vehicle = num_lanes * 1000 / (float)traffic_density / traffic_speed;

  // Simulate traffic flow
  for (int i=0; i<length_road*1000; ++i) {
    if (i % (int)(1000 / (float)traffic_density) == 0) {
      total_delay += delay_per_vehicle;
    }
  }

  // Output results
  printf("Average Delay per Vehicle: %.2f seconds\n", delay_per_vehicle);
  printf("Total Delay on Road: %.2f minutes\n", total_delay/60);

  return 0;
}