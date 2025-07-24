//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random number generator with the current time

  printf("Initializing C Wireless Network Scanner...\n");
  printf("Scanning for wireless networks...\n");

  int num_networks = rand() % 10; // randomly generate the number of networks found
  if (num_networks == 0) {
    printf("No wireless networks found.\n");
    return 0;
  }

  printf("Found %d wireless networks:\n", num_networks);

  // generate fake network names and signal strengths
  char* network_names[num_networks];
  int network_strengths[num_networks];
  int i;
  for (i = 0; i < num_networks; i++) {
    char* name = (char*)malloc(sizeof(char) * 10); // randomly generate a network name
    int j;
    for (j = 0; j < 9; j++) {
      name[j] = 'A' + rand() % 26;
    }
    name[9] = '\0';
    network_names[i] = name;

    int strength = rand() % 100; // randomly generate a network signal strength
    network_strengths[i] = strength;
  }

  // print out the networks found and their signal strengths
  for (i = 0; i < num_networks; i++) {
    printf("  %s - %d%%\n", network_names[i], network_strengths[i]);
    free(network_names[i]); // free the memory used for the network name
  }

  printf("Scan complete.\n");
  return 0;
}