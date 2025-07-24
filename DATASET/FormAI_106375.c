//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int latency = rand() % 50 + 50;
  int jitter = rand() % 20 + 10;
  int packet_loss = rand() % 10;

  printf("=== Network Quality of Service (QoS) Monitor ===\n");
  printf("Latency: %dms\n", latency);
  printf("Jitter: %dms\n", jitter);
  printf("Packet Loss: %d%%\n", packet_loss);

  if (latency >= 50 && latency <= 100) {
    printf("Latency is within acceptable range.\n");
  } else {
    printf("Latency is outside acceptable range.\n");
    // Send alert to network administrator
  }

  if (jitter >= 10 && jitter <= 30) {
    printf("Jitter is within acceptable range.\n");
  } else {
    printf("Jitter is outside acceptable range.\n");
    // Send alert to network administrator
  }

  if (packet_loss <= 5) {
    printf("Packet loss is within acceptable range.\n");
  } else {
    printf("Packet loss is outside acceptable range.\n");
    // Send alert to network administrator
  }
  
  return 0;
}