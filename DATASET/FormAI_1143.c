//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Network Topology Mapper!\n");
  // Let's start by getting the number of devices on the network
  int num_devices;
  printf("How many devices are on your network? ");
  scanf("%d", &num_devices);

  // Let's allocate some memory for the device names
  char **device_names = (char **)malloc(num_devices * sizeof(char *));
  
  // Now let's get the name of each device
  for (int i = 0; i < num_devices; i++) {
    printf("Enter the name of device %d: ", i+1);
    device_names[i] = (char *)malloc(20 * sizeof(char));
    scanf("%s", device_names[i]);
  }

  printf("\n");
  // Now let's create the network topology map
  for (int i = 0; i < num_devices; i++) {
    printf("%s ", device_names[i]);
    for (int j = 0; j < num_devices; j++) {
      if (i == j) {
        printf("  -  ");
      } else if (i < j) {
        printf("  %d  ", rand() % 100 + 1);
      } else {
        printf("  %c  ", 'X');
      }
    }
    printf("\n");
  }

  // Let's free the memory we allocated for the device names
  for (int i = 0; i < num_devices; i++) {
    free(device_names[i]);
  }
  free(device_names);
  
  return 0;
}