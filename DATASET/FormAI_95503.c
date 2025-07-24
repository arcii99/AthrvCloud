//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to parse the string and return the amount of used RAM
float get_ram_usage(char* str) {
    int index = -1;
    float usage = -1;

    // Search for the digit in the string
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            index = i;
            break;
        }
    }

    // Extract the number from the string
    if (index != -1) {
        sscanf(&str[index], "%f", &usage);
    }

    return usage;
}

int main() {
  // Initialise file variable to read memory info from
  FILE *file_ptr;
  // Buffer to hold memory info (each line is around 80 characters)
  char buffer[80];
  // Amount of RAM used as a percentage
  float ram_usage;
  // Command to pass to the terminal
  char* command = "free";
  // Output of the command
  char output[100];

  // Loop to periodically check memory usage
  while(true) {
    // Open the command in the terminal and read output
    file_ptr = popen(command, "r");

    // Check the file was opened correctly
    if (!file_ptr) {
        printf("Failed to open command\n");
        exit(1);
    }

    // Read the output from the command
    while(fgets(buffer, 80, file_ptr)) {
      // Check if the line contains memory info
      if (strncmp(buffer, "Mem:", 4) == 0) {
        // Parse the memory info to get the RAM usage
        ram_usage = get_ram_usage(buffer);

        // Output the RAM usage to the console
        printf("RAM usage: %0.2f%%\n", ram_usage);
      }
    }

    // Close the file pointer
    pclose(file_ptr);

    // Sleep for 1 second before checking again
    sleep(1);
  }

  return 0;
}