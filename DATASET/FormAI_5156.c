//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 100

typedef struct {
  int flight_num;
  int num_bags;
} Flight;

typedef struct {
  int bag_id;
  int flight_num;
} Baggage;

void print_flight_info(Flight f);
void print_baggage_info(Baggage b);
int get_random_num_bags();

int main() {
  // Create array of flights
  Flight flights[] = {
    {101, get_random_num_bags()},
    {102, get_random_num_bags()},
    {103, get_random_num_bags()},
    {104, get_random_num_bags()},
    {105, get_random_num_bags()}
  };
  
  // Create array of baggages
  Baggage baggage[MAX_BAGS];
  int num_bags = 0; // Tracks total number of bags
  
  // Loop through each flight and add its bags to the baggage array
  for(int i = 0; i < sizeof(flights)/sizeof(flights[0]); i++) {
    for(int j = 0; j < flights[i].num_bags; j++) {
      Baggage b = {num_bags + 1, flights[i].flight_num};
      baggage[num_bags] = b;
      num_bags++;
    }
  }
  
  // Print out all the baggage
  printf("All baggage:\n");
  for(int i = 0; i < num_bags; i++) {
    print_baggage_info(baggage[i]);
  }
  
  // Print out all flights and their baggage
  printf("\nFlights and their baggage:\n");
  for(int i = 0; i < sizeof(flights)/sizeof(flights[0]); i++) {
    print_flight_info(flights[i]);
    for(int j = 0; j < num_bags; j++) {
      if(baggage[j].flight_num == flights[i].flight_num) {
        print_baggage_info(baggage[j]);
      }
    }
  }
  
  return 0;
}

void print_flight_info(Flight f) {
  printf("Flight %d - %d bags\n", f.flight_num, f.num_bags);
}

void print_baggage_info(Baggage b) {
  printf("Baggage ID: %d, Flight Num: %d\n", b.bag_id, b.flight_num);
}

int get_random_num_bags() {
  return rand() % 26 + 25; // Between 25 and 50 bags per flight
}