//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIFI_SIGNAL_FILE "/proc/net/wireless"
#define MAX_LINE_LENGTH 1024

int main() {
  while (1) {
    FILE *fp = fopen(WIFI_SIGNAL_FILE, "r");
    if (!fp) {
      perror("Failed to open Wi-Fi signal file");
      sleep(1);
      continue;
    }

    char line[MAX_LINE_LENGTH];
    // Ignore the first 2 lines since we only need the signal level
    fgets(line, MAX_LINE_LENGTH, fp);
    fgets(line, MAX_LINE_LENGTH, fp);

    // Get the signal level from the Wi-Fi signal file
    float signal_level = 0.0;
    char *signal_str = strstr(line, "-");
    if (signal_str) {
      signal_level = strtof(signal_str, NULL);
    }

    fclose(fp);

    // Output the signal level
    printf("Wi-Fi signal strength: %.0f dBm\n", signal_level);

    // Wait for 1 second before checking again
    sleep(1);
  }

  return 0;
}