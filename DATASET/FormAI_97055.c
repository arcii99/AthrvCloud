//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BAGS 1000
#define MAX_WEIGHT 50
#define MAX_BELTS 10

typedef struct{
  char airline[10];
  int flight_number;
  int destination_gate;
  int num_bags;
  float total_weight;
  int bag_list[MAX_BAGS];
} Flight;

typedef struct{
  int belt_num;
  int num_bags;
  float total_weight;
  int bag_list[MAX_BAGS];
} Belt;

Flight flights[MAX_BELTS];
Belt belts[MAX_BELTS];
int lost_bag_count = 0;

void print_flight_info(int index){
  printf("Airline: %s\n", flights[index].airline);
  printf("Flight number: %d\n", flights[index].flight_number);
  printf("Destination gate: %d\n", flights[index].destination_gate);
  printf("Number of bags: %d\n", flights[index].num_bags);
  printf("Total weight: %.2f\n", flights[index].total_weight);
}

void print_belt_info(int index){
  printf("Belt number: %d\n", belts[index].belt_num);
  printf("Number of bags: %d\n", belts[index].num_bags);
  printf("Total weight: %.2f\n", belts[index].total_weight);
}

void add_bag_to_flight(int flight_index, int bag_id){
  if(flights[flight_index].num_bags == MAX_BAGS){
    printf("The flight is now full.\n");
    return;
  }

  flights[flight_index].bag_list[flights[flight_index].num_bags] = bag_id;
  flights[flight_index].num_bags++;
  printf("The bag has been added to the flight.\n");
}

void add_bag_to_belt(int belt_index, int bag_id, float bag_weight){
  if((belts[belt_index].num_bags == MAX_BAGS) || ((belts[belt_index].total_weight + bag_weight) > MAX_WEIGHT)){
    printf("The belt is now full or overweight.\n");
    return;
  }

  belts[belt_index].bag_list[belts[belt_index].num_bags] = bag_id;
  belts[belt_index].num_bags++;
  belts[belt_index].total_weight += bag_weight;
  printf("The bag has been added to the belt.\n");
}

void remove_bag_from_belt(int belt_index, int bag_index){
  if(belts[belt_index].num_bags == 0){
    printf("The belt is empty.\n");
    return;
  }

  int bag_id = belts[belt_index].bag_list[bag_index];
  float bag_weight = (float) (rand() % 50 + 1); //random bag weight between 1 to 50 pounds
  int flight_index = -1;

  for(int i = 0; i < MAX_BELTS; i++){
    for(int j = 0; j < flights[i].num_bags; j++){
      if(flights[i].bag_list[j] == bag_id){
        flight_index = i;
        break;
      }
    }
  }

  if(flight_index == -1){
    lost_bag_count++;
    printf("The bag is lost!\n");
  }
  else{
    flights[flight_index].num_bags--;
    flights[flight_index].total_weight -= bag_weight;
    printf("The bag has been loaded onto the plane.\n");
  }

  belts[belt_index].num_bags--;
  belts[belt_index].total_weight -= bag_weight;
  printf("The bag has been removed from the belt.\n");
}

void display_lost_bag_count(){
  printf("The number of lost bags is: %d\n", lost_bag_count);
}

int main(){
  //initialize belts
  for(int i = 0; i < MAX_BELTS; i++){
    belts[i].belt_num = i + 1;
    belts[i].num_bags = 0;
    belts[i].total_weight = 0;
  }

  //simulate two flights
  for(int i = 0; i < 2; i++){
    printf("Enter the airline: ");
    scanf("%s", flights[i].airline);
    printf("Enter the flight number: ");
    scanf("%d", &flights[i].flight_number);
    printf("Enter the destination gate: ");
    scanf("%d", &flights[i].destination_gate);

    printf("Enter the number of bags: ");
    scanf("%d", &flights[i].num_bags);

    for(int j = 0; j < flights[i].num_bags; j++){
      int bag_id = rand() % 1000 + 1; //random bag id between 1 to 1000
      float bag_weight = (float) (rand() % 50 + 1); //random bag weight between 1 to 50 pounds
      flights[i].bag_list[j] = bag_id;
      flights[i].total_weight += bag_weight;

      //add the bag to a random belt
      int belt_index = rand() % MAX_BELTS;
      add_bag_to_belt(belt_index, bag_id, bag_weight);
    }
  }

  //simulate belt operations
  bool running = true;
  int option, belt_index, bag_index;

  while(running){
    printf("\n\nBelt operations:\n");
    printf("-----------------\n");
    printf("1. Add bag to belt\n");
    printf("2. Remove bag from belt\n");
    printf("3. Display belt info\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &option);

    switch(option){
      case 1:
        printf("Enter the belt number: ");
        scanf("%d", &belt_index);
        printf("Enter the bag id: ");
        int bag_id;
        scanf("%d", &bag_id);
        printf("Enter the bag weight: ");
        float bag_weight;
        scanf("%f", &bag_weight);
        add_bag_to_belt(belt_index - 1, bag_id, bag_weight);
        break;
      case 2:
        printf("Enter the belt number: ");
        scanf("%d", &belt_index);
        printf("Enter the bag index: ");
        scanf("%d", &bag_index);
        remove_bag_from_belt(belt_index - 1, bag_index);
        break;
      case 3:
        printf("Enter the belt number: ");
        scanf("%d", &belt_index);
        print_belt_info(belt_index - 1);
        break;
      case 4:
        running = false;
        break;
      default:
        printf("Invalid option.\n");
        break;
    }
  }

  //display flight and lost bag info
  for(int i = 0; i < 2; i++){
    printf("\n\nFlight %d Info:\n", i+1);
    printf("-----------------\n");
    print_flight_info(i);
  }

  printf("\n\n");
  display_lost_bag_count();

  return 0;
}