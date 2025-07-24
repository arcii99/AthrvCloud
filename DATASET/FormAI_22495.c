//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char network[30][50]; // An array of 30 strings to store detected networks
   int signal[30]; // An array of 30 integers to store signal strength of networks
   int n = 0; // Count of detected networks
   char medieval[50]; // A string to store medieval-style message
   
   printf("Scanning for wireless networks...\n");   
   // Code to scan for available networks and their strength
   // ...

   // Display the detected networks and signal strength
   for (int i = 0; i < n; i++) {
      printf("%s  Signal: %d\n", network[i], signal[i]);
   }
   
   printf("\n");
   // Check if any network has a signal strength greater than or equal to 80
   int found = 0;
   for (int i = 0; i < n; i++) {
      if (signal[i] >= 80) {
         found = 1; // Found at least one network with signal strength >= 80
         sprintf(medieval, "A great network named %s has been detected with a signal strength of %d!\n", network[i], signal[i]);
         break;
      }
   }
   
   if (found) {
      printf("\n");
      printf("######################################\n");
      printf("#                                    #\n");
      printf("#              ALERT!                #\n");
      printf("#                                    #\n");
      printf("######################################\n\n");
      printf("%s\n", medieval);
   } else {
      printf("\nNo strong network has been detected. Keep searching!\n");
   }
   
   return 0;
}