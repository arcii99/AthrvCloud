//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  const int MAX_RAM_USAGE = 512; // Maximum RAM usage in MB
  const int SAMPLE_INTERVAL = 1; // Interval to sample RAM usage in seconds 

  char command[100], output[100];
  memset(command, 0, 100);
  memset(output, 0, 100);

  sprintf(command, "ps -p %d -o %%cpu,%%mem", getpid()); // Command to get current process CPU usage and memory usage
  while(1) {
    system(command); // Execute command to get current process CPU and memory usage
    system("sleep 1s"); // Sleep for 1 second to wait for next sample interval

    FILE* fp = popen(command, "r"); // Open a PIPE to read from command's output
    fgets(output, 100, fp); // Read the output from PIPE
    pclose(fp); // Close the PIPE

    char *cpu_str, *mem_str;
    cpu_str = strtok(output, " "); // Tokenize CPU usage string
    mem_str = strtok(NULL, " "); // Tokenize memory usage string

    double mem_usage = atof(mem_str); // Convert memory usage to double
    mem_usage /= 1024; // Convert to MB

    if(mem_usage > MAX_RAM_USAGE) { // If memory usage is greater than maximum allowed RAM usage
      printf("Warning: Memory usage exceeds limit. Memory usage: %.2fMB\n", mem_usage);
    }
  }

  return 0;
}