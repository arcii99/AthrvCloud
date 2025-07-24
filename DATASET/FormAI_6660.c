//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   int signal_strength, distance;
   printf("Enter Wi-Fi signal strength (in dBm): ");
   scanf("%d", &signal_strength);
   
   distance = pow(10, ((signal_strength - 30) / 27.55));
   
   if(distance <= 1)
      printf("The Wi-Fi signal is very strong!\n");
   else if(distance > 1 && distance <= 3)
      printf("The Wi-Fi signal is strong.\n");
   else if(distance > 3 && distance <= 5)
      printf("The Wi-Fi signal is moderate.\n");
   else if(distance > 5 && distance <= 7)
      printf("The Wi-Fi signal is weak.\n");
   else
      printf("The Wi-Fi signal is very weak!\n");
   
   return 0;
}