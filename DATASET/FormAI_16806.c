//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
// Mysterious WiFi Signal Strength Analyzer

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
   int signal_strength, distance;
   float freq, signal_strength_dbm, signal_strength_mw, eirp, path_loss, received_power_dbm, received_power_mw, snr;

   printf("Enter the frequency of signal in GHz: ");
   scanf("%f", &freq);

   printf("Enter the signal strength in dBm: ");
   scanf("%d", &signal_strength);

   printf("Enter the EIRP in dBm: ");
   scanf("%f", &eirp);

   signal_strength_dbm = signal_strength;
   signal_strength_mw = pow(10, signal_strength/10);
   
   path_loss = eirp - 20*log10(distance) - 20*log10(freq) + 20*log10(1000);
   
   received_power_dbm = eirp - path_loss;
   received_power_mw = pow(10, received_power_dbm/10);
   
   snr = signal_strength_mw/received_power_mw;
   
   printf("\n+++ Calculating Data +++\n");
   printf("Signal Strength (dBm): %d dBm\n", signal_strength);
   printf("Signal Strength (mW): %f mW\n", signal_strength_mw);
   printf("Distance: %d m\n", distance);
   printf("EIRP (dBm): %f dBm\n", eirp);
   printf("Path Loss: %f dBm\n", path_loss);
   printf("Received Power (dBm): %f dBm\n", received_power_dbm);
   printf("Received Power (mW): %f mW\n", received_power_mw);
   printf("SNR: %f\n", snr);
   
   if (signal_strength >= -50) {
      printf("Signal strength is excellent.\n");
   }
   else if (signal_strength >= -60 && signal_strength < -50) {
      printf("Signal strength is good.\n");
   }
   else if (signal_strength >= -70 && signal_strength < -60) {
      printf("Signal strength is fair.\n");
   }
   else if (signal_strength >= -80 && signal_strength < -70) {
      printf("Signal strength is poor.\n");
   }
   else {
      printf("Signal strength is very poor.\n");
   }
   
   return 0;
}