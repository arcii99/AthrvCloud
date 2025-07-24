//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
// C Network Topology Mapper Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100  // Maximum number of devices to be mapped

struct device {
  char name[20];
  int num_connections;
  struct device* connections[MAX_DEVICES];
};

int add_device(struct device* devices, char* name, int num_devices) {
  if (num_devices >= MAX_DEVICES) {
    printf("Max number of devices exceeded!\n");
    return num_devices;
  }

  struct device* new_device = malloc(sizeof(struct device));
  strcpy(new_device->name, name);
  new_device->num_connections = 0;

  devices[num_devices++] = *new_device;
  return num_devices;
}

void connect_devices(struct device* devices, int index1, int index2) {
  devices[index1].connections[devices[index1].num_connections++] = &devices[index2];
  devices[index2].connections[devices[index2].num_connections++] = &devices[index1];
}

void print_topology(struct device* devices, int num_devices) {
  printf("Network Topology:\n");
  for (int i = 0; i < num_devices; i++) {
    printf("%s -> ", devices[i].name);
    for (int j = 0; j < devices[i].num_connections; j++) {
      printf("%s ", devices[i].connections[j]->name);
    }
    printf("\n");
  }
}

int main() {
  // Create an array of devices
  struct device devices[MAX_DEVICES];

  // Initialize with some devices
  int num_devices = add_device(devices, "Device 1", 0);
  num_devices = add_device(devices, "Device 2", num_devices);
  num_devices = add_device(devices, "Device 3", num_devices);

  // Connect the devices
  connect_devices(devices, 0, 1);
  connect_devices(devices, 1, 2);

  // Print the network topology
  print_topology(devices, num_devices);

  return 0;
}