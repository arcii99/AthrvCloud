//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int delay = 0;
  int packet_loss = 0;
  float bandwidth = 0;
  srand(time(0));

  // Simulate network traffic
  for(int i = 0; i < 1000; i++) {
    // Generate random values for delay, packet loss and bandwidth
    delay = rand() % 100;
    packet_loss = rand() % 10;
    bandwidth = (float)rand()/(float)(RAND_MAX/100);

    // Check if network QoS is good
    if(delay < 50 && packet_loss < 5 && bandwidth > 50) {
      printf("Network QoS is good!\n");
    }
    // Check if network QoS is fair
    else if((delay >= 50 && delay < 70) || (packet_loss >= 5 && packet_loss < 8) || (bandwidth <= 50 && bandwidth > 30)) {
      printf("Network QoS is fair.\n");
    }
    // Check if network QoS is poor
    else {
      printf("Network QoS is poor.\n");
    }

    // Delay loop to simulate network delay
    for(int j = 0; j < delay; j++) {
      // Do nothing
    }
  }

  return 0;
}