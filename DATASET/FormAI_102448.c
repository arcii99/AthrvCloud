//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int year = rand() % 2019;
  printf("Welcome to the Time Travel Simulator!\n");
  printf("You have been randomly transported to the year %d!\n", year);
  printf("What would you like to do first?\n");
  printf("[1] Explore the surroundings\n");
  printf("[2] Check your inventory\n");
  printf("[3] Talk to the locals\n");
  printf("[4] Try to find a way back\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("You take a look around and notice that things are very different from your time. The buildings look different and there is no sign of modern technology. You feel like you are in a different world altogether.\n");
      break;
    case 2:
      printf("You check your pockets and find that you have a map, a compass, and a pocket knife. Looks like you came prepared for the journey!\n");
      break;
    case 3:
      printf("You approach a local and try to strike up a conversation. They seem surprised by your appearance and after some initial shock, they are able to communicate with you. You learn a lot about their culture and way of life.\n");
      break;
    case 4:
      printf("You try to find a way back to your time by asking around and looking for clues. Unfortunately, you are not able to find anything useful and are stuck in this time period for the foreseeable future.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
  }
  printf("Thank you for using the Time Travel Simulator!\n");
  return 0;
}