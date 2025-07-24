//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100             // Maximum number of bags in the airport
#define MAX_CONVEYOR_LEN 10      // Maximum length of conveyor belts
#define MAX_LUGGAGE_WEIGH 50     // Maximum weight of each luggage
#define CONVEYOR_SPEED 1         // Speed at which conveyor belts move

typedef struct {
   int arrival_time;
   int weight;
} Baggage;

// Generates a random baggage with arrival time and weight
Baggage generate_baggage() {
   Baggage new_baggage;
   new_baggage.arrival_time = rand() % 100;
   new_baggage.weight = rand() % MAX_LUGGAGE_WEIGH;
   return new_baggage;
}

int main() {
   srand(time(0));  // Initialize random seed

   int conveyor1[MAX_CONVEYOR_LEN] = {0};  // Initialize empty conveyor belts
   int conveyor2[MAX_CONVEYOR_LEN] = {0};
   Baggage waiting_room[MAX_BAGS] = {0};  // Initialize empty waiting room
   
   int bags_on_conveyor1 = 0;   // Number of bags on conveyor 1
   int bags_on_conveyor2 = 0;   // Number of bags on conveyor 2
   int current_baggage = 0;     // Index of current baggage in the waiting room
   int time = 0;                // Time passed
   
   // Loop until all bags are processed
   while (current_baggage < MAX_BAGS) {
      // Process all waiting bags that arrived before or at current time
      while (waiting_room[current_baggage].arrival_time <= time && current_baggage < MAX_BAGS) {
         int conveyor_choice = rand() % 2;  // Choose a random conveyor
         if (conveyor_choice == 0 && bags_on_conveyor1 < MAX_CONVEYOR_LEN) {
            conveyor1[bags_on_conveyor1] = waiting_room[current_baggage].weight;
            bags_on_conveyor1++;
         }
         else if (bags_on_conveyor2 < MAX_CONVEYOR_LEN) {
            conveyor2[bags_on_conveyor2] = waiting_room[current_baggage].weight;
            bags_on_conveyor2++;
         }
         current_baggage++;
      }
      
      // Move bags on conveyor 1
      for (int i = 0; i < bags_on_conveyor1; i++) {
         if (i + CONVEYOR_SPEED < bags_on_conveyor1) {
            conveyor1[i] = conveyor1[i + CONVEYOR_SPEED];
         }
         else {
            conveyor1[i] = 0;
         }
      }
      bags_on_conveyor1 -= CONVEYOR_SPEED;
      if (bags_on_conveyor1 < 0) {
         bags_on_conveyor1 = 0;
      }
      
      // Move bags on conveyor 2
      for (int i = 0; i < bags_on_conveyor2; i++) {
         if (i + CONVEYOR_SPEED < bags_on_conveyor2) {
            conveyor2[i] = conveyor2[i + CONVEYOR_SPEED];
         }
         else {
            conveyor2[i] = 0;
         }
      }
      bags_on_conveyor2 -= CONVEYOR_SPEED;
      if (bags_on_conveyor2 < 0) {
         bags_on_conveyor2 = 0;
      }
      
      // Print conveyor belts
      printf("Time: %d\n", time);
      printf("Conveyor 1: ");
      for (int i = 0; i < MAX_CONVEYOR_LEN; i++) {
         if (i < bags_on_conveyor1) {
            printf("%d ", conveyor1[i]);
         }
         else {
            printf("- ");
         }
      }
      printf("\n");
      
      printf("Conveyor 2: ");
      for (int i = 0; i < MAX_CONVEYOR_LEN; i++) {
         if (i < bags_on_conveyor2) {
            printf("%d ", conveyor2[i]);
         }
         else {
            printf("- ");
         }
      }
      printf("\n\n");
      
      time++;  // Increment time
   }
   
   return 0;
}