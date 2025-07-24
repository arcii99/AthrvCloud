//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_NUM_AP 20

struct AccessPoint {
  char ssid[MAX_SSID_LENGTH];
  int signal_strength;
};

void print_ap_list(struct AccessPoint ap_list[], int num_ap) {
  printf("SSID\tSignal Strength\n");
  for(int i = 0; i < num_ap; i++) {
    printf("%s\t%d dBm\n", ap_list[i].ssid, ap_list[i].signal_strength);
  }
}

void get_ap_list(struct AccessPoint ap_list[], int *num_ap) {
  // Assume we have a function to get the list of access points here.
  // For demonstration purposes, we will just hard-code some values.
  strcpy(ap_list[0].ssid, "MyWiFi");
  ap_list[0].signal_strength = -50;
  strcpy(ap_list[1].ssid, "MyHotspot");
  ap_list[1].signal_strength = -70;
  strcpy(ap_list[2].ssid, "CoffeeShopWiFi");
  ap_list[2].signal_strength = -60;
  *num_ap = 3;
}

int main() {
  struct AccessPoint ap_list[MAX_NUM_AP];
  int num_ap = 0;
  
  get_ap_list(ap_list, &num_ap);
  
  printf("Found a total of %d access points:\n", num_ap);
  print_ap_list(ap_list, num_ap);
  
  int strongest_ap_index = 0;
  for(int i = 1; i < num_ap; i++) {
    if(ap_list[i].signal_strength > ap_list[strongest_ap_index].signal_strength) {
      strongest_ap_index = i;
    }
  }
  
  printf("Strongest access point: %s\n", ap_list[strongest_ap_index].ssid);
  
  return 0;
}