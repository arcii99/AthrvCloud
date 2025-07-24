//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORKS 10

struct network {
  char* name;
  int signal_strength;
};

void print_networks(struct network* networks, int cnt) {
  printf("Scanning for networks...\n");
  for (int i = 0; i < cnt; i++) {
    printf("Network found: %s (signal strength: %d)\n", networks[i].name, networks[i].signal_strength);
  }
}

int main() {
  srand(42);
  int num_networks = rand() % MAX_NETWORKS + 1;
  struct network networks[num_networks];
  
  char buffer[100];
  for (int i = 0; i < num_networks; i++) {
    sprintf(buffer, "WiFi Network %d", i + 1);
    int signal_strength = rand() % 100;
    networks[i].name = (char*)malloc(sizeof(char) * strlen(buffer));
    strcpy(networks[i].name, buffer);
    networks[i].signal_strength = signal_strength;
  }

  print_networks(networks, num_networks);

  // Cleaning up
  for (int i = 0; i < num_networks; i++) {
    free(networks[i].name);
  }

  return 0;
}