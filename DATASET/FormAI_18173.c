//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: protected
/* Airport Baggage Handling Simulation */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NO_OF_CHECKIN_DESKS 4
#define NO_OF_CONVEYORS 3
#define NO_OF_SCANNERS 2
#define MAX_BAGS 50

struct bag {
   int bag_id;
   int weight;
   int destination;
};

struct checkin_desk {
   int id;
   int no_of_bags;
   struct bag bag_list[MAX_BAGS];
};

struct scanner {
   int id;
   int no_of_bags;
   struct bag bag_list[MAX_BAGS];
};

struct conveyor {
   int id;
   int no_of_bags;
   struct bag bag_list[MAX_BAGS];
};

int main() {

   /* Initialize random number generator for bag weights */
   srand(time(NULL));

   /* Create check-in desks */
   struct checkin_desk desks[NO_OF_CHECKIN_DESKS];
   for(int i = 0; i < NO_OF_CHECKIN_DESKS; i++) {
      desks[i].id = i+1;
      desks[i].no_of_bags = 0;
   }

   /* Create scanners */
   struct scanner scanners[NO_OF_SCANNERS];
   for(int i = 0; i < NO_OF_SCANNERS; i++) {
      scanners[i].id = i+1;
      scanners[i].no_of_bags = 0;
   }

   /* Create conveyors */
   struct conveyor conveyors[NO_OF_CONVEYORS];
   for(int i = 0; i < NO_OF_CONVEYORS; i++) {
      conveyors[i].id = i+1;
      conveyors[i].no_of_bags = 0;
   }

   /* Generate bags */
   struct bag bags[MAX_BAGS];
   for(int i = 0; i < MAX_BAGS; i++) {
      bags[i].bag_id = i+1;
      bags[i].weight = rand() % 20 + 1;
      bags[i].destination = rand() % 5 + 1;
   }

   /* Assign bags to check-in desks */
   int j = 0;
   for(int i = 0; i < MAX_BAGS; i++) {
      desks[j].bag_list[desks[j].no_of_bags++] = bags[i];
      j = (j + 1) % NO_OF_CHECKIN_DESKS;
   }

   /* Scan and sort bags */
   for(int i = 0; i < NO_OF_SCANNERS; i++) {
      /* Assign bags to scanners */
      for(j = 0; j < NO_OF_CHECKIN_DESKS; j++) {
         int k = 0;
         while(k < desks[j].no_of_bags) {
            if(scanners[i].no_of_bags < MAX_BAGS) {
               scanners[i].bag_list[scanners[i].no_of_bags++] = desks[j].bag_list[k];
               desks[j].no_of_bags--;
               for(int l = k; l < desks[j].no_of_bags; l++) {
                  desks[j].bag_list[l] = desks[j].bag_list[l+1];
               }
            } else {
               break;
            }
            k++;
         }
      }

      /* Scan bags */
      for(j = 0; j < scanners[i].no_of_bags; j++) {
         if(scanners[i].bag_list[j].weight > 10) {
            /* Send overweight bags to special conveyor */
            conveyors[NO_OF_CONVEYORS-1].bag_list[conveyors[NO_OF_CONVEYORS-1].no_of_bags++] = scanners[i].bag_list[j];
            for(int k = j; k < scanners[i].no_of_bags-1; k++) {
               scanners[i].bag_list[k] = scanners[i].bag_list[k+1];
            }
            j--;
            scanners[i].no_of_bags--;
         } else {
            /* Sort bags based on destination */
            int dest = scanners[i].bag_list[j].destination;
            if(dest > 0 && dest <= 3) {
               conveyors[0].bag_list[conveyors[0].no_of_bags++] = scanners[i].bag_list[j];
            } else {
               conveyors[1].bag_list[conveyors[1].no_of_bags++] = scanners[i].bag_list[j];
            }
         }
      }
   }

   /* Display conveyor contents */
   printf("Conveyor 1: ");
   for(int i = 0; i < conveyors[0].no_of_bags; i++) {
      printf("%d ", conveyors[0].bag_list[i].bag_id);
   }
   printf("\nConveyor 2: ");
   for(int i = 0; i < conveyors[1].no_of_bags; i++) {
      printf("%d ", conveyors[1].bag_list[i].bag_id);
   }
   printf("\nSpecial Conveyor: ");
   for(int i = 0; i < conveyors[2].no_of_bags; i++) {
      printf("%d ", conveyors[2].bag_list[i].bag_id);
   }

   return 0;
}