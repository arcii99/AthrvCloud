//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED   "\033[1;31m" 
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

int main()
{
  char choice;
  int min_time, max_time, yellow_time, red_time, green_time;

  printf("Are you ready to control the traffics with me? (y/n): ");
  scanf("%c", &choice);
  if (choice == 'n' || choice == 'N') {
    printf("Okay, let's play later.\n");
    exit(0);
  }

  printf("\nAlright, let's start!\n");

  printf("Enter minimum time for traffic light (in seconds): ");
  scanf("%d", &min_time);

  printf("Enter maximum time for traffic light (in seconds): ");
  scanf("%d", &max_time);

  printf("Enter yellow light time (in seconds): ");
  scanf("%d", &yellow_time);

  green_time = min_time;
  red_time = max_time - green_time - yellow_time;

  while (1) {
    printf(GREEN "Green Light\n" RESET);
    sleep(green_time);

    printf(YELLOW "Yellow Light\n" RESET);
    sleep(yellow_time);

    printf(RED "Red Light\n" RESET);
    sleep(red_time);
  }

  return 0;
}