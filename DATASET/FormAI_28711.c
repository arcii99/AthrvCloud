//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include<stdio.h>
int main()
{
  int floors, curr_floor, des_floor;
  printf("Enter the number of floors in the building: ");
  scanf("%d", &floors);
  
  do
  {
    printf("Which floor are you currently on? (1 - %d): ", floors);
    scanf("%d", &curr_floor);
  } while(curr_floor < 1 || curr_floor > floors);
  
  do
  {
    printf("Which floor would you like to go to? (1 - %d): ", floors);
    scanf("%d", &des_floor);
  } while(des_floor < 1 || des_floor > floors || des_floor == curr_floor);
  
  printf("Elevator is now taking you from floor %d to floor %d.\n", curr_floor, des_floor);
  
  if (curr_floor < des_floor)
  {
    printf("Going up...\n");
    while (curr_floor < des_floor)
    {
      printf("Now on floor %d.\n", curr_floor);
      curr_floor++;
    }
    printf("You have reached your destination on floor %d.\n", curr_floor);
  }
  else
  {
    printf("Going down...\n");
    while (curr_floor > des_floor)
    {
      printf("Now on floor %d.\n", curr_floor);
      curr_floor--;
    }
    printf("You have reached your destination on floor %d.\n", curr_floor);
  }
  
  return 0;
}