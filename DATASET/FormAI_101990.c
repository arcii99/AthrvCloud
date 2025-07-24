//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // set random seed using current time

  int packet_loss = rand() % 101; // simulate packet loss percentage
  int latency = rand() % 201 + 50; // simulate latency in milliseconds

  printf("Welcome to the Medieval Network Quality of Service (QoS) monitor!\n\n");

  printf("The current packet loss rate is %d%%.\n", packet_loss);

  if (packet_loss < 10) {
    printf("The network is in excellent shape.\n");
  } else if (packet_loss < 30) {
    printf("The network is performing adequately.\n");
  } else if (packet_loss < 50) {
    printf("The network is experiencing some issues. Please be patient.\n");
  } else {
    printf("The network is under heavy load. Expect significant delays.\n");
  }

  printf("The current latency is %dms.\n", latency);

  if (latency < 100) {
    printf("Network performance is excellent.\n");
  } else if (latency < 150) {
    printf("Network performance is acceptable, but could be better.\n");
  } else if (latency < 200) {
    printf("Network performance is poor. You may experience delays and lag.\n");
  } else {
    printf("Network performance is terrible. Expect significant delays and lag.\n");
  }

  return 0;
}