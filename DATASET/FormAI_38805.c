//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int current_light;

void print_traffic_light() {
  switch (current_light) {
    case RED:
      printf("RED\n");
      break;
    case YELLOW:
      printf("YELLOW\n");
      break;
    case GREEN:
      printf("GREEN\n");
      break;
    default:
      printf("Error: Invalid light state\n");
  }
}

void change_light(int new_light) {
  current_light = new_light;
  print_traffic_light();
}

void handle_interrupt(int signum) {
  switch (current_light) {
    case RED:
      change_light(GREEN);
      break;
    case YELLOW:
      change_light(RED);
      break;
    case GREEN:
      change_light(YELLOW);
      break;
    default:
      printf("Error: Invalid light state\n");
  }
}

void setup_interrupts() {
  struct sigaction sa;
  sa.sa_handler = handle_interrupt;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;
  sigaction(SIGINT, &sa, NULL);
}

int main() {
  current_light = RED;
  setup_interrupts();
  
  printf("Starting Traffic Light Controller...\n");
  print_traffic_light();
  
  while (true) {
    switch (current_light) {
      case RED:
        sleep(5);
        change_light(GREEN);
        break;
      case YELLOW:
        sleep(2);
        change_light(RED);
        break;
      case GREEN:
        sleep(8);
        change_light(YELLOW);
        break;
      default:
        printf("Error: Invalid light state\n");
    }
  }
  
  return 0;
}