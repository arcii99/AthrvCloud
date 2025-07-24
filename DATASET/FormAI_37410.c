//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

  // Declare variables
  char *RAM_zone_1 = "Alpha";
  char *RAM_zone_2 = "Beta";
  char *RAM_zone_3 = "Gamma";
  char *RAM_zone_4 = "Delta";
  int used_RAM_1 = 0;
  int used_RAM_2 = 0;
  int used_RAM_3 = 0;
  int used_RAM_4 = 0;
  
  // Initialize random number generator
  srand(time(NULL));
  
  // Infinite loop for surrealism
  while (1) {
    
    // Generate random RAM usage
    used_RAM_1 = rand() % 101;
    used_RAM_2 = rand() % 101;
    used_RAM_3 = rand() % 101;
    used_RAM_4 = rand() % 101;
    
    // Create header
    printf("\n\n\n\n\n\n");
    printf("     █████╗ ██╗   ██╗████████╗███████╗██╗  ██╗    ████████╗ ██████╗     ██████╗ ███████╗██╗███╗   ██╗    \n");
    printf("    ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║    ╚══██╔══╝██╔═══██╗    ██╔══██╗██╔════╝██║████╗  ██║    \n");
    printf("    ███████║██║   ██║   ██║   █████╗  ███████║       ██║   ██║   ██║    ██████╔╝█████╗  ██║██╔██╗ ██║    \n");
    printf("    ██╔══██║██║   ██║   ██║   ██╔══╝  ██╔══██║       ██║   ██║   ██║    ██╔═══╝ ██╔══╝  ██║██║╚██╗██║    \n");
    printf("    ██║  ██║╚██████╔╝   ██║   ███████╗██║  ██║       ██║   ╚██████╔╝    ██║     ███████╗██║██║ ╚████║    \n");
    printf("    ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═╝       ╚═╝    ╚═════╝     ╚═╝     ╚══════╝╚═╝╚═╝  ╚═══╝    \n\n\n\n");
    printf("   %s :", RAM_zone_1);
    for (int i = 0; i < used_RAM_1; i++) printf("█");
    for (int i = 0; i < 100 - used_RAM_1; i++) printf(" ");
    printf(": %d%%\n", used_RAM_1);
    printf("   %s :", RAM_zone_2);
    for (int i = 0; i < used_RAM_2; i++) printf("█");
    for (int i = 0; i < 100 - used_RAM_2; i++) printf(" ");
    printf(": %d%%\n", used_RAM_2);
    printf("   %s :", RAM_zone_3);
    for (int i = 0; i < used_RAM_3; i++) printf("█");
    for (int i = 0; i < 100 - used_RAM_3; i++) printf(" ");
    printf(": %d%%\n", used_RAM_3);
    printf("   %s :", RAM_zone_4);
    for (int i = 0; i < used_RAM_4; i++) printf("█");
    for (int i = 0; i < 100 - used_RAM_4; i++) printf(" ");
    printf(": %d%%\n", used_RAM_4);
    printf("   -----------------------------------------------------------------------------------------------------\n");
    printf("   Press Ctrl+C to exit.\n\n");
    fflush(stdout);
    
    // Wait before refreshing
    sleep(1);
  }
  
  return 0;
}