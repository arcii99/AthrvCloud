//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LEN 32

typedef struct {
  char ssid[MAX_SSID_LEN];
  double frequency;
  int signal_strength;
} Network;

int compare_freq(const void *a, const void *b) {
  const Network *na = (const Network *)a;
  const Network *nb = (const Network *)b;
  return (int)(na->frequency - nb->frequency);
}

int main() {
  Network networks[MAX_NETWORKS];
  int num_networks = 0;

  // simulate scanning for wireless networks
  printf("Scanning for wireless networks...\n");
  for (int i = 0; i < MAX_NETWORKS; i++) {
    if (rand() % 2 == 0) { // found network
      snprintf(networks[num_networks].ssid, MAX_SSID_LEN, "Network%d", num_networks + 1);
      networks[num_networks].frequency = 2.4 + ((double)(rand() % 10) / 10);
      networks[num_networks].signal_strength = -50 - (rand() % 50);
      num_networks++;
    }
  }

  // sort networks by frequency
  qsort(networks, num_networks, sizeof(Network), compare_freq);

  // print table of found networks
  printf("Found %d networks:\n", num_networks);
  printf("SSID\tFrequency\tSignal Strength\n");
  printf("----\t---------\t---------------\n");
  for (int i = 0; i < num_networks; i++) {
    printf("%s\t%.1f GHz\t\t%d dBm\n", networks[i].ssid, networks[i].frequency, networks[i].signal_strength);
  }

  // calculate and print mathematical summary
  double mean_freq = 0;
  int max_strength = -100;
  int min_strength = 0;
  int total_strength = 0;
  for (int i = 0; i < num_networks; i++) {
    mean_freq += networks[i].frequency;
    if (networks[i].signal_strength > max_strength) {
      max_strength = networks[i].signal_strength;
    }
    if (networks[i].signal_strength < min_strength) {
      min_strength = networks[i].signal_strength;
    }
    total_strength += networks[i].signal_strength;
  }
  mean_freq /= num_networks;

  double variance = 0;
  for (int i = 0; i < num_networks; i++) {
    variance += pow(networks[i].frequency - mean_freq, 2);
  }
  variance /= num_networks;

  double stddev = sqrt(variance);

  printf("\nMathematical Summary:\n");
  printf("Mean Frequency: %.1f GHz\n", mean_freq);
  printf("Standard Deviation of Frequency: %.3f GHz\n", stddev);
  printf("Max Signal Strength: %d dBm\n", max_strength);
  printf("Min Signal Strength: %d dBm\n", min_strength);
  printf("Average Signal Strength: %d dBm\n", total_strength / num_networks);

  return 0;
}