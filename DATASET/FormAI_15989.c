//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_DEVICE_NAME_LENGTH 20

struct Device {
  char name[MAX_DEVICE_NAME_LENGTH];
  int signal_strength;
};

struct Device devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char* name, int signal_strength) {
  if (num_devices < MAX_DEVICES) {
    strcpy(devices[num_devices].name, name);
    devices[num_devices].signal_strength = signal_strength;
    num_devices++;
  }
  else {
    printf("Maximum number of devices reached!\n");
  }
}

void display_devices() {
  printf("***** Wi-Fi Signal Strength Analyzer *****\n");
  printf("* %20s %10s *\n", "Device Name", "Signal");
  printf("*****************************************\n");
  for (int i = 0; i < num_devices; i++) {
    printf("* %20s %10d *\n", devices[i].name, devices[i].signal_strength);
  }
  printf("*****************************************\n");
}

int main() {
  // Sample data
  add_device("Device 1", -75);
  add_device("Device 2", -60);
  add_device("Device 3", -90);

  display_devices();
  return 0;
}