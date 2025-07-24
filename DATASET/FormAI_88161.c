//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 20
#define MAX_WEIGHT 30

enum {
  ARRIVAL,
  DEPARTURE
};

typedef struct Bag {
  int id;
  int weight;
  int flight_number;
} Bag;

void print_bag(Bag b) {
  printf("Bag Id: %d, Weight: %d, Flight: %d\n", b.id, b.weight, b.flight_number);
}

int main() {
  srand(time(NULL));
  int op_count = 0;
  Bag inbound_bags[MAX_BAGS];
  Bag outbound_bags[MAX_BAGS];
  int inbound_bag_count = 0;
  int outbound_bag_count = 0;
  
  while (op_count < 10) {
    // Simulate bag arrival
    int rand_weight = rand() % MAX_WEIGHT;
    int rand_flight_number = rand() % 100;
    printf("New Bag Arrival\n");
    Bag b = {
      .id = inbound_bag_count,
      .weight = rand_weight,
      .flight_number = rand_flight_number
    };
    print_bag(b);
    inbound_bags[inbound_bag_count++] = b;
    
    // Simulate bag departure
    if (outbound_bag_count < inbound_bag_count) {
      Bag departing_bag = inbound_bags[outbound_bag_count++];
      printf("Departing Bag\n");
      print_bag(departing_bag);
      outbound_bags[outbound_bag_count++] = departing_bag;
    }

    op_count++;
  }
  
  printf("Total Baggage Processed: %d\n", op_count);
  printf("Total Inbound Bags: %d\n", inbound_bag_count);
  printf("Total Outbound Bags: %d\n", outbound_bag_count);

  return 0;
}