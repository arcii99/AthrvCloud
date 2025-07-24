//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>

int main()
{
  printf("\n\n!!!! Welcome to the GPS Navigation Simulation !!!!\n\n");
  
  int destination;
  printf("Enter your destination:\n1. City Center\n2. Shopping Mall\n3. Airport\n");
  scanf("%d", &destination);
  
  switch(destination)
  {
    case 1:
      printf("\nYou have selected the City Center as your destination\n");
      break;
    case 2:
      printf("\nYou have selected the Shopping Mall as your destination\n");
      break;
    case 3:
      printf("\nYou have selected the Airport as your destination\n");
      break;
    default:
      printf("\nInvalid Destination! Please select a valid option.\n");
      return 0;
  }
  
  printf("Calculating route to your destination...\n\n");
  
  int progress = 0;
  
  while(progress <= 100)
  {
    printf("Navigating... %d%%\n", progress);
    progress += 10;
  }
  
  printf("\nYou have reached your destination!\n\n");
  
  return 0;
}