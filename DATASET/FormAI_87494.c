//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEVICES 10
#define MAX_SIGNAL_STRENGTH 100

int main() {
  int devices[MAX_DEVICES];
  int i, j, signalStrength;
  
  // Initialize random number generator
  srand(time(NULL));

  // Generate signal strength for each device
  for (i = 0; i < MAX_DEVICES; i++) {
    signalStrength = rand() % MAX_SIGNAL_STRENGTH;
    devices[i] = signalStrength;
  }

  // Print signal strength for each device
  printf("Signal Strength:\n");
  for (i = 0; i < MAX_DEVICES; i++) {
    printf("Device %d: ", i+1);
    for (j = 0; j < devices[i]; j++) {
      printf("*");
    }
    printf("\n");
  }

  // Find average signal strength
  int sum = 0;
  for (i = 0; i < MAX_DEVICES; i++) {
    sum += devices[i];
  }
  float avg = (float) sum / MAX_DEVICES;

  // Print average signal strength
  printf("Average Signal Strength: %.2f\n", avg);

  // List devices with weak signal strength
  int weakDevices[MAX_DEVICES];
  int numWeakDevices = 0;
  for (i = 0; i < MAX_DEVICES; i++) {
    if (devices[i] < (int) avg) {
      weakDevices[numWeakDevices++] = i+1;
    }
  }
  if (numWeakDevices > 0) {
    printf("%d Weak Devices: ", numWeakDevices);
    for (i = 0; i < numWeakDevices; i++) {
      printf("%d ", weakDevices[i]);
    }
    printf("\n");
  } else {
    printf("No weak devices found.\n");
  }

  return 0;
}