//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define SSID_LENGTH 20

typedef struct WirelessNetwork {
   char ssid[SSID_LENGTH];
   int signal_strength;
} WirelessNetwork;

void scan_networks(WirelessNetwork *networks, int max_networks) {
   // simulate scanning for networks
   
   int num_networks = rand() % (max_networks + 1);

   for (int i = 0; i < num_networks; i++) {
      // generate random ssid
      char ssid[SSID_LENGTH];
      for (int j = 0; j < SSID_LENGTH - 1; j++) {
         ssid[j] = 'A' + rand() % 26;
      }
      ssid[SSID_LENGTH - 1] = '\0';

      // generate random signal strength
      int signal_strength = rand() % 101;

      // add network to list
      WirelessNetwork network;
      strncpy(network.ssid, ssid, SSID_LENGTH);
      network.signal_strength = signal_strength;
      networks[i] = network;
   }
}

void print_networks(WirelessNetwork *networks, int num_networks) {
   for (int i = 0; i < num_networks; i++) {
      printf("%2d) %-20s %3d%%\n", i+1, networks[i].ssid, networks[i].signal_strength);
   }
}

int main() {
   WirelessNetwork networks[MAX_NETWORKS];
   scan_networks(networks, MAX_NETWORKS);
   int num_networks = sizeof(networks) / sizeof(networks[0]);
   print_networks(networks, num_networks);

   return 0;
}