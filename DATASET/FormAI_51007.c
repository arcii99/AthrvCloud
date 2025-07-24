//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include <stdio.h>

int main() {
  char* SSID_Name = "MyWiFiNetwork";
  int signal_strength = 80;

  printf("Scanning WiFi signal strength on %s...\n", SSID_Name);

  if (signal_strength >= 70 && signal_strength < 100) {
    printf("Signal strength is very good! You'll have fast internet.\n");
  } else if (signal_strength >= 50 && signal_strength < 70) {
    printf("Signal strength is good! You'll have decent internet.\n");
  } else if (signal_strength >= 25 && signal_strength < 50) {
    printf("Signal strength is poor. You might experience slow internet.\n");
  } else if (signal_strength < 25) {
    printf("Signal strength is very poor. You might not be able to connect to the internet.\n");
  } else {
    printf("Signal strength not detected on %s. Check the router or try again later.\n", SSID_Name);
  }

  printf("Would you like to run a WiFi speed test? (Y/N)\n");
  char answer;

  scanf("%c", &answer);

  if (answer == 'Y') {
    printf("Running WiFi speed test...\n");
    //Code to run speed test goes here.
  } else {
    printf("No problem. Have a nice day!\n");
  }

  return 0;
}