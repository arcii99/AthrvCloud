//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_WEIGHT 50 //maximum weight of the baggage
#define MAX_BAGS 100 //maximum number of bags
#define MAX_TIME 30 //maximum time for baggage handling
#define MAX_TRAYS 5 //maximum number of trays

int main(){
  srand(time(0)); //seeding random number generator with current time
  int bags[MAX_BAGS]; //array to store weights of bags
  int num_bags = rand() % MAX_BAGS + 1; //randomly generating number of bags between 1 and MAX_BAGS
  int i, j, total_weight = 0;
  for(i=0;i<num_bags;i++){
    bags[i] = rand() % MAX_WEIGHT + 1; //randomly generating weight of each bag between 1 and MAX_WEIGHT
    total_weight += bags[i];
  }
  printf("Total number of bags: %d\n", num_bags);
  printf("Total weight of bags: %d\n", total_weight);

  int trays[MAX_TRAYS] = {0}; //array to store the number of bags in each tray
  int tray_weight[MAX_TRAYS] = {0}; //array to store the total weight of bags in each tray
  int num_trays = 0;
  int max_tray_weight = MAX_WEIGHT * MAX_TRAYS; //maximum weight a tray can hold
  int time_elapsed = 0; //time elapsed in baggage handling
  while(num_bags > 0){
    for(i=0;i<MAX_TRAYS;i++){
      if(trays[i] < 3){ //if tray is not full
        for(j=0;j<num_bags;j++){
          if(bags[j] + tray_weight[i] <= max_tray_weight){ //if baggage can be added to the tray
            trays[i]++;
            tray_weight[i] += bags[j];
            num_bags--;
            printf("Bag %d added to Tray %d\n", j+1, i+1);
            if(num_bags == 0) break;
          }
        }
      }
    }
    time_elapsed++; //increment time elapsed
    if(time_elapsed == MAX_TIME){ //if time limit reached
      printf("Time limit (%d mins) reached. Handling stopped.\n", MAX_TIME);
      break;
    }
  }
  num_trays = MAX_TRAYS - num_bags;
  printf("Total number of trays used: %d\n", num_trays);

  return 0;
}