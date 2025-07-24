//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  // Initialize variables
  int latency = 0;
  int bandwidth = 0;
  int packet_loss_rate = 0;
  
  // Welcome message
  printf("Welcome to the Network Quality of Service monitor!\n");
  printf("Please enter the current latency in milliseconds: ");
  scanf("%d", &latency);
  printf("Please enter the available bandwidth in megabits per second: ");
  scanf("%d", &bandwidth);
  printf("Please enter the current packet loss rate as a percentage: ");
  scanf("%d", &packet_loss_rate);

  // Check packet loss rate
  if (packet_loss_rate >= 0 && packet_loss_rate <= 5) {
    printf("\n\nPacket loss rate is acceptable.\n");
  } else {
    printf("\n\nPacket loss rate is above threshold.\n");
  }
  
  // Check latency and bandwidth
  if (latency <= 100 && bandwidth >= 50) {
    printf("Network quality is excellent!\n");
  } else if (latency <= 250 && bandwidth >= 25) {
    printf("Network quality is good.\n");
  } else if (latency <= 500 && bandwidth >= 10) {
    printf("Network quality is fair.\n");
  } else {
    printf("Network quality is poor.\n");
  }
  
  return 0;
}