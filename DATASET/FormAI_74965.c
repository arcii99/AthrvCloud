//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: calm
#include <stdio.h>
#include <stdlib.h>

//define the traffic light states using enums
enum TL_STATE {RED, YELLOW, GREEN} tl_state;

//define the traffic light directions using enums
enum TL_DIRECTION {NORTH_SOUTH, EAST_WEST};

//define the traffic light struct
struct TrafficLight {
   enum TL_DIRECTION direction;
   enum TL_STATE state;
};

//initialize the traffic light for north-south direction
struct TrafficLight tl_north_south = {NORTH_SOUTH, RED};

//initialize the traffic light for east-west direction
struct TrafficLight tl_east_west = {EAST_WEST, GREEN};

//function to update the state of the traffic light for north-south direction
void update_tl_north_south() {
   switch(tl_north_south.state) {
      case RED:
         tl_north_south.state = GREEN;
         break;
      case YELLOW:
         tl_north_south.state = RED;
         break;
      case GREEN:
         tl_north_south.state = YELLOW;
         break;
      default:
         printf("Invalid state!");
         exit(0);
   }
}

//function to update the state of the traffic light for east-west direction
void update_tl_east_west() {
   switch(tl_east_west.state) {
      case RED:
         tl_east_west.state = GREEN;
         break;
      case YELLOW:
         tl_east_west.state = RED;
         break;
      case GREEN:
         tl_east_west.state = YELLOW;
         break;
      default:
         printf("Invalid state!");
         exit(0);
   }
}

//function to display the state of the traffic light for north-south direction
void display_tl_north_south() {
   printf("North-South traffic light: ");
   switch(tl_north_south.state) {
      case RED:
         printf("RED\n");
         break;
      case YELLOW:
         printf("YELLOW\n");
         break;
      case GREEN:
         printf("GREEN\n");
         break;
      default:
         printf("Invalid state!");
         exit(0);
   }
}

//function to display the state of the traffic light for east-west direction
void display_tl_east_west() {
   printf("East-West traffic light: ");
   switch(tl_east_west.state) {
      case RED:
         printf("RED\n");
         break;
      case YELLOW:
         printf("YELLOW\n");
         break;
      case GREEN:
         printf("GREEN\n");
         break;
      default:
         printf("Invalid state!");
         exit(0);
   }
}

//main function to control the traffic lights
int main() {
   int i;
   
   //display the initial states of the traffic lights
   printf("INITIAL STATE\n");
   display_tl_north_south();
   display_tl_east_west();
   
   //change the states of the traffic lights every 4 seconds
   for(i=0; i<10; i++) {
      printf("\n");
   
      //update the state of the traffic light for north-south direction
      update_tl_north_south();
      display_tl_north_south();
   
      //update the state of the traffic light for east-west direction
      update_tl_east_west();
      display_tl_east_west();
   
      //wait for 4 seconds
      sleep(4);
   }
   
   return 0;
}