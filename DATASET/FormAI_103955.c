//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#define MAX_BAGS 100

struct Baggage {
  int id;                 // Baggage ID
  int weight;             // Weight of the baggage in kg
  char destination[50];   // The destination of the baggage
  int conveyor;           // The conveyor number where the baggage is currently present
};

struct Conveyor {
  int id;                 // Conveyor ID
  int max_capacity;       // Maximum capacity of the conveyor in kg
  int current_weight;     // Current capacity of the conveyor in kg
  int bags_count;         // Number of bags on the conveyor
  struct Baggage bags[MAX_BAGS]; // Array of bags on this conveyor
};

int main() {
  struct Conveyor conveyors[5]; // Five conveyors present in the airport
  int i, j, choice, bag_id;
  
  // Initializing the conveyors
  for(i=0; i<5; i++) {
    conveyors[i].id = i+1;
    conveyors[i].max_capacity = 1000;
    conveyors[i].current_weight = 0;
    conveyors[i].bags_count = 0;
  }
  
  while(1) {
    printf("\nAirport Baggage Handling System\n");
    printf("1. Add Baggage\n");
    printf("2. View Conveyors\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("\nEnter the baggage ID: ");
        scanf("%d", &bag_id);
        struct Baggage new_bag;
        new_bag.id = bag_id;
        printf("Enter the weight of the baggage: ");
        scanf("%d", &new_bag.weight);
        printf("Enter the destination of the baggage: ");
        scanf("%s", new_bag.destination);
        int conveyor_index;
        for(i=0; i<5; i++) {
          if(conveyors[i].current_weight+new_bag.weight <= conveyors[i].max_capacity) {
            conveyor_index = i;
            conveyors[i].bags[conveyors[i].bags_count] = new_bag;
            conveyors[i].current_weight += new_bag.weight;
            conveyors[i].bags_count++;
            printf("Baggage added to conveyor %d successfully!\n", i+1);
            break;
          }
        }
        if(i == 5) {
          printf("Sorry, no conveyor available to add baggage. Try again later!\n");
        }
        break;
      case 2:
        printf("\nConveyor Details:\n");
        for(i=0; i<5; i++) {
          printf("Conveyor %d:\n", conveyors[i].id);
          printf("Current capacity: %d/%d kg\n", conveyors[i].current_weight, conveyors[i].max_capacity);
          printf("Bags:\n");
          for(j=0; j<conveyors[i].bags_count; j++) {
            printf("%d. Baggage ID: %d, Weight: %d kg, Destination: %s\n", j+1, conveyors[i].bags[j].id, conveyors[i].bags[j].weight, conveyors[i].bags[j].destination);
          }
          printf("\n");
        }
        break;
      case 3:
        printf("\nThank you for using Airport Baggage Handling System!\n");
        return 0;
        break;
      default:
        printf("Invalid Choice. Try again!\n");
        break;
    }
  }
  return 0;
}