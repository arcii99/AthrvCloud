//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define MAX_SSIDS 20

struct WifiSignalStrength {
  char ssid[32];
  int signal_strength;
};

struct WifiSignalStrength wifi_signal_strengths[MAX_SSIDS];
int num_ssids;

void get_all_wifi_signal_strengths() {
  char buffer[BUFFER_SIZE];
  char command[] = "sudo iwlist wlan0 scan | grep -ioE 'ssid:\"[^\"]+\"|signal level[:|=]-[0-9]+'";
  FILE *fp = popen(command, "r");
  
  if (fp == NULL) {
    printf("Failed to execute the command.\n");
    exit(1);
  }
  
  char *ssid = NULL;
  int signal_strength = 0;

  // Parse the output of the `sudo iwlist wlan0 scan` command.
  while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
    if (strstr(buffer, "SSID:") != NULL) {
      ssid = strtok(buffer+6, "\"\n");
    } else if (strstr(buffer, "Signal level:") != NULL || strstr(buffer, "Signal Level=") != NULL) {
      signal_strength = atoi(strtok(buffer+13, "=\n "));

      if (signal_strength <= 0) {
        signal_strength = abs(signal_strength - 100);
      }
      
      // Store the SSID and signal strength in our struct array.
      if (ssid != NULL && num_ssids < MAX_SSIDS) {
        struct WifiSignalStrength wifi_signal_strength;
        strncpy(wifi_signal_strength.ssid, ssid, sizeof(wifi_signal_strength.ssid)-1);
        wifi_signal_strengths[num_ssids] = wifi_signal_strength;
        wifi_signal_strengths[num_ssids].signal_strength = signal_strength;
        num_ssids++;
      }
    }
  }
  
  pclose(fp);

  // Sort the SSIDs by signal strength (descending order).
  for (int i = 0; i < num_ssids; i++) {
    for (int j = i+1; j < num_ssids; j++) {
      if (wifi_signal_strengths[i].signal_strength < wifi_signal_strengths[j].signal_strength) {
        struct WifiSignalStrength temp = wifi_signal_strengths[i];
        wifi_signal_strengths[i] = wifi_signal_strengths[j];
        wifi_signal_strengths[j] = temp;
      }
    }
  }
}

void print_wifi_signal_strengths() {
  printf("\n%-32s %s\n", "SSID", "Signal Strength");

  for (int i = 0; i < num_ssids; i++) {
    printf("%-32s %-3d%%\n", wifi_signal_strengths[i].ssid, wifi_signal_strengths[i].signal_strength);
  }
}

int main(int argc, char *argv[]) {
  get_all_wifi_signal_strengths();
  print_wifi_signal_strengths();
  
  return 0;
}