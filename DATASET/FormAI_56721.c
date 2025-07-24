//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50
#define MAX_CONNECTIONS 100

typedef struct {
  char device_name[20];
  int device_id;
} Device;

typedef struct {
  int connection_id;
  int source_id;
  int dest_id;
  int cost;
} Connection;

Device devices[MAX_DEVICES];
Connection connections[MAX_CONNECTIONS];

int num_devices = 0;
int num_connections = 0;

void add_device(char* name) {
  Device device;
  strncpy(device.device_name, name, 20);
  device.device_id = num_devices++;
  devices[device.device_id] = device;
}

void add_connection(int source_id, int dest_id, int cost) {
  Connection connection;
  connection.connection_id = num_connections++;
  connection.source_id = source_id;
  connection.dest_id = dest_id;
  connection.cost = cost;
  connections[connection.connection_id] = connection;
}

void print_topology() {
  printf("\nNetwork Topology:\n");
  printf("==================\n");

  for(int i = 0; i < num_devices; i++) {
    printf("Device %d (%s) is connected to:\n", devices[i].device_id, devices[i].device_name);

    for(int j = 0; j < num_connections; j++) {
      if(connections[j].source_id == i) {
        printf("  - Device %d (%s) with cost %d\n", connections[j].dest_id, devices[connections[j].dest_id].device_name, connections[j].cost);
      } else if(connections[j].dest_id == i) {
        printf("  - Device %d (%s) with cost %d\n", connections[j].source_id, devices[connections[j].source_id].device_name, connections[j].cost);
      }
    }

    printf("\n");
  }
}

int main() {
  // Add devices to the network
  add_device("Router1");
  add_device("Router2");
  add_device("Switch1");
  add_device("Server1");
  add_device("Server2");

  // Add connections between devices
  add_connection(0, 1, 5);
  add_connection(0, 2, 2);
  add_connection(1, 3, 3);
  add_connection(1, 4, 7);
  add_connection(2, 3, 1);
  add_connection(2, 4, 4);
  add_connection(3, 4, 6);

  // Print the network topology
  print_topology();

  return 0;
}