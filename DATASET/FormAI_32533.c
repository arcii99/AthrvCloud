//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  system("clear"); // Clear the screen
  printf("Welcome to the C RAM usage monitor!\n");
  sleep(2); // Wait for 2 seconds
  
  printf("Checking the current RAM usage...\n");
  sleep(1);
  
  int ram_usage = system("free -m | awk 'NR==2{printf \"RAM usage: %.2f%%\", $3*100/$2 }'"); // Get the current RAM usage in percentage
  printf("\n"); // Add a new line for formatting
  
  if (ram_usage > 80) {
    printf("Oh no! The RAM usage is over 80%%!\n");
    printf("Please close some programs or upgrade your RAM.\n");
  } else {
    printf("Phew! The RAM usage is below 80%%.\n");
    printf("Keep working and keep an eye on the RAM usage!\n");
  }
  
  return 0;
}