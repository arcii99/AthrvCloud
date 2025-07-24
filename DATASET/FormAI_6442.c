//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // The website to monitor
  char *website = "https://www.example.com";

  // The command to get the response headers
  char command[255];
  snprintf(command, sizeof(command), "curl -s -I %s", website);

  // Loop forever
  while (1) {
    // Get the response headers
    FILE *pipe = popen(command, "r");

    if (pipe) {
      // Parse the response headers
      char response[255];
      int status_code = -1;
      while (fgets(response, sizeof(response), pipe)) {
        if (strstr(response, "HTTP")) {
          sscanf(response, "%*s %d", &status_code);
        }
      }

      // Close the pipe
      pclose(pipe);

      // Check the status code
      if (status_code == 200) {
        printf("%s is up!\n", website);
      } else {
        printf("%s is down!\n", website);
      }
    } else {
      printf("Error opening pipe!\n");
    }

    // Wait for 5 seconds before checking again
    sleep(5);
  }

  return 0;
}