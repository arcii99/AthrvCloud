//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BAGGAGE 100
#define MAX_LENGTH 20
#define MAX_DEST 3

struct Baggage {
  char baggage_number[MAX_LENGTH];
  char destination[MAX_LENGTH];
};

void print_status(struct Baggage baggage_list[], int length) {
  printf("Current Baggage Status:\n");
  for (int i = 0; i < length; i++) {
    printf("Baggage %s destined for %s\n", baggage_list[i].baggage_number, baggage_list[i].destination);
  }
  printf("\n");
}

void handle_baggage(struct Baggage baggage_list[], int length) {
  struct Baggage temp;
  for (int i = 0; i < length; i++) {
    for (int j = i+1; j < length; j++) {
      if (baggage_list[i].destination[0] > baggage_list[j].destination[0]) {
        temp = baggage_list[i];
        baggage_list[i] = baggage_list[j];
        baggage_list[j] = temp;
      }
    }
  }
  printf("Baggage Successfully Handled!\n\n");
}

int main() {
  srand(time(0));
  
  // Initialize Baggage List
  struct Baggage baggage_list[MAX_BAGGAGE];
  for (int i = 0; i < MAX_BAGGAGE; i++) {
    int dest = rand() % MAX_DEST;
    switch (dest) {
      case 0:
        sprintf(baggage_list[i].destination, "Night City");
        break;
      case 1:
        sprintf(baggage_list[i].destination, "Neo Tokyo");
        break;
      case 2:
        sprintf(baggage_list[i].destination, "Mega City One");
        break;
    }
    sprintf(baggage_list[i].baggage_number, "BAG-%03d", i+1);
  }
  
  // Print Initial Status
  print_status(baggage_list, MAX_BAGGAGE);
  
  // Handle Baggage
  handle_baggage(baggage_list, MAX_BAGGAGE);
  
  // Print Final Status
  print_status(baggage_list, MAX_BAGGAGE);
  
  return 0;
}