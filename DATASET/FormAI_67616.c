//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char *wifi_signal = "Strong"; // Default signal strength
   int signal_strength = 70; // Default signal strength value

   // Get user input for signal strength
   printf("Enter the signal strength (0-100): ");
   scanf("%d", &signal_strength);

   // Check if signal strength is within range
   if (signal_strength < 0 || signal_strength > 100) {
      printf("Invalid signal strength! Please enter a value between 0 and 100.\n");
      return 1; // Return an error code
   }

   // Determine signal strength description based on value
   if (signal_strength < 20) {
      wifi_signal = "Weak";
   } else if (signal_strength < 50) {
      wifi_signal = "Fair";
   } else if (signal_strength < 70) {
      wifi_signal = "Good";
   } else {
      wifi_signal = "Strong";
   }

   // Print results
   printf("The signal strength is %s (%d%%).\n", wifi_signal, signal_strength);

   return 0; // Return success code
}