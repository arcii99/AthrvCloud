//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: interoperable
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

bool running;
int greenTime = 10;
int yellowTime = 3;
int redTime = 15;

void handleSignal(int signal) {
  running = false;
}

void setGreen() {
  printf("GREEN\n");
  sleep(greenTime);
}

void setYellow() {
  printf("YELLOW\n");
  sleep(yellowTime);
}

void setRed() {
  printf("RED\n");
  sleep(redTime);
}

int main() {
  running = true;
  signal(SIGINT, handleSignal);

  while (running) {
    setGreen();
    setYellow();
    setRed();
    setYellow();
  }

  printf("\nTraffic light controller terminated.\n");

  return 0;
}