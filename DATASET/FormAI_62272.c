//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  //initialize variables
  int light1 = 0;
  int light2 = 0;
  int light3 = 0;
  int light4 = 0;
  int room = 0;
  char input[10] = "";

  //Greeting message
  printf("Welcome to the Smart Home Light Control System!\n");

  // Loop for user input
  while(1){
    //Display current status
    printf("\nRoom 1: Light %d\n", light1);
    printf("Room 2: Light %d\n", light2);
    printf("Room 3: Light %d\n", light3);
    printf("Room 4: Light %d\n", light4);

    //Prompt user for input
    printf("\nEnter room number or 'all' to control all rooms: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    //Handle user input
    if(strcmp(input, "all") == 0){
      //Prompt user for action
      printf("\nWhat do you want to do?\n");
      printf("1. Turn all lights on\n");
      printf("2. Turn all lights off\n");
      printf("Enter action number: ");
      fgets(input, sizeof(input), stdin);
      int action = atoi(input);
      input[strcspn(input, "\n")] = 0;

      //Handle action
      switch(action){
        case 1: //Turn all lights on
          printf("\nTurning all lights on...\n");
          light1 = 1;
          light2 = 1;
          light3 = 1;
          light4 = 1;
          break;
        case 2: //Turn all lights off
          printf("\nTurning all lights off...\n");
          light1 = 0;
          light2 = 0;
          light3 = 0;
          light4 = 0;
          break;
        default:
          printf("\nInvalid action.\n");
          break;
      }
    }
    else if(atoi(input) >= 1 && atoi(input) <= 4){
      //Set current room
      room = atoi(input);

      //Prompt user for action
      printf("\nRoom %d: Light %d\n", room, room==1?light1:room==2?light2:room==3?light3:light4);
      printf("What do you want to do?\n");
      printf("1. Turn light on\n");
      printf("2. Turn light off\n");
      printf("Enter action number: ");
      fgets(input, sizeof(input), stdin);
      int action = atoi(input);
      input[strcspn(input, "\n")] = 0;

      //Handle action
      switch(action){
        case 1: //Turn light on
          printf("\nTurning light %d on...\n", room);
          if(room == 1){
            light1 = 1;
          }
          else if(room == 2){
            light2 = 1;
          }
          else if(room == 3){
            light3 = 1;
          }
          else{
            light4 = 1;
          }
          break;
        case 2: //Turn light off
          printf("\nTurning light %d off...\n", room);
          if(room == 1){
            light1 = 0;
          }
          else if(room == 2){
            light2 = 0;
          }
          else if(room == 3){
            light3 = 0;
          }
          else{
            light4 = 0;
          }
          break;
        default: //Invalid action
          printf("\nInvalid action.\n");
          break;
      }
    }
    else{ //Invalid room
      printf("\nInvalid room number.\n");
    }
  }

  return 0;
}