//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_DEVICE_NAME 20

typedef struct _Device {
   char name[MAX_DEVICE_NAME];
   int connections[MAX_DEVICES];
   int numConnections;
} Device;

void addDevice(Device* devices, int* numDevices, char* name) {
   Device device;
   strcpy(device.name, name);
   device.numConnections = 0;
   devices[*numDevices] = device;
   *numDevices += 1;
}

void connectDevices(Device* devices, int* numDevices, char* device1, char* device2) {
   int i, index1 = -1, index2 = -1;
   for (i = 0; i < *numDevices; i++) {
      if (strcmp(devices[i].name, device1) == 0) {
         index1 = i;
      }
      if (strcmp(devices[i].name, device2) == 0) {
         index2 = i;
      }
      if (index1 != -1 && index2 != -1) {
         break;
      }
   }
   devices[index1].connections[devices[index1].numConnections] = index2;
   devices[index2].connections[devices[index2].numConnections] = index1;
   devices[index1].numConnections += 1;
   devices[index2].numConnections += 1;
}

void printTopology(Device* devices, int numDevices) {
   int i, j;
   for (i = 0; i < numDevices; i++) {
      printf("%s: ", devices[i].name);
      for (j = 0; j < devices[i].numConnections; j++) {
         printf("%s ", devices[devices[i].connections[j]].name);
      }
      printf("\n");
   }
}

int main() {
   int numDevices = 0;
   Device devices[MAX_DEVICES];
   addDevice(devices, &numDevices, "Router1");
   addDevice(devices, &numDevices, "Switch1");
   addDevice(devices, &numDevices, "Switch2");
   addDevice(devices, &numDevices, "PC1");
   addDevice(devices, &numDevices, "PC2");
   connectDevices(devices, &numDevices, "Router1", "Switch1");
   connectDevices(devices, &numDevices, "Router1", "Switch2");
   connectDevices(devices, &numDevices, "Switch1", "PC1");
   connectDevices(devices, &numDevices, "Switch2", "PC2");
   printTopology(devices, numDevices);
   return 0;
}