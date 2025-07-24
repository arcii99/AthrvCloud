//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Initializing variables and arrays
   int num_packets = 100;
   double threshold = 0.7;
   int num_intrusions = 0;
   double packets_sent[num_packets];
   double current_rate[num_packets];
   srand(time(NULL));
   
   // Generating random packet sizes and calculating current rate
   for(int i = 0; i < num_packets; i++) {
      packets_sent[i] = rand() % 100;
      current_rate[i] = packets_sent[i] / num_packets;
   }
   
   // Checking current rate against threshold for intrusions
   for(int i = 0; i < num_packets; i++) {
      if(current_rate[i] > threshold) {
         num_intrusions++;
      }
   }
   
   // Outputting results
   printf("Number of packets sent: %d\n", num_packets);
   printf("Threshold for intrusion: %.2f\n", threshold);
   printf("Number of intrusions detected: %d\n", num_intrusions);
   
   return 0;
}