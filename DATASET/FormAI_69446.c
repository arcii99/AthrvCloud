//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of access points that can be scanned.
#define MAX_ACCESS_POINTS 100

int main() {

  printf("C Wireless Network Scanner\n");

  // Define the access points array to store SSID and signal strength.
  char access_points[MAX_ACCESS_POINTS][25];
  int signal_strengths[MAX_ACCESS_POINTS];

  // Simulate scanning by filling the array with random values.
  int num_access_points = rand() % MAX_ACCESS_POINTS;
  for (int i = 0; i < num_access_points; i++) {
    sprintf(access_points[i], "SSID_%d", i+1);
    signal_strengths[i] = rand() % 101 - 100;
  }

  // Print the access points and signal strengths.
  printf("\nAccess Points:\n");
  for (int i = 0; i < num_access_points; i++) {
    printf("%s\t%ddb\n", access_points[i], signal_strengths[i]);
  }

  return 0;
}