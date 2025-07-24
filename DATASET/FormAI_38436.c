//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ada Lovelace
/* 
  This is a Wi-Fi Signal Strength Analyzer program written in Ada Lovelace style.
  The program displays the signal strength of available Wi-Fi networks in range. 
  Press 'q' to quit the program.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
  const int MAX_NETWORKS = 10; // Maximum number of available networks to show
  int networks = 0; // Actual number of available networks
  int signal_strength[MAX_NETWORKS]; // Available network signal strength
  char network_names[MAX_NETWORKS][20]; // Available network names
  char input_char; // User input
  int i; // Index variable
  
  // Print program heading
  printf("Wi-Fi Signal Strength Analyzer (Ada Lovelace Style)\n");
  printf("-------------------------------------------------\n\n");

  // Simulate searching for available Wi-Fi networks
  printf("Searching for available Wi-Fi networks...\n");
  
  // Assume some networks are found
  networks = 5;
  strcpy(network_names[0], "Network 1");
  strcpy(network_names[1], "Network 2");
  strcpy(network_names[2], "Network 3");
  strcpy(network_names[3], "Network 4");
  strcpy(network_names[4], "Network 5");
  signal_strength[0] = -50;
  signal_strength[1] = -68;
  signal_strength[2] = -70;
  signal_strength[3] = -80;
  signal_strength[4] = -90;

  // Print available networks
  printf("\n%d Wi-Fi networks found:\n\n", networks);
  printf("%-20s Signal Strength\n", "Network Name");
  for (i = 0; i < networks; i++)
    printf("%-20s %ddBm\n", network_names[i], signal_strength[i]);

  // Main loop
  while (1) {
    // Wait for user input
    printf("\nPress 'q' to quit...\n");
    input_char = getchar();

    // Quit program if 'q' is pressed
    if (input_char == 'q') {
      printf("\nQuitting program... Goodbye!\n");
      break;
    }

    // Otherwise, update signal strength and print available networks
    printf("\nUpdating network signal strength...\n");
    for (i = 0; i < networks; i++)
      signal_strength[i] += (rand() % 20) - 10;
    printf("\n%d Wi-Fi networks found:\n\n", networks);
    printf("%-20s Signal Strength\n", "Network Name");
    for (i = 0; i < networks; i++)
      printf("%-20s %ddBm\n", network_names[i], signal_strength[i]);
  }

  return 0;
}