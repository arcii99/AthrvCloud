//FormAI DATASET v1.0 Category: Smart home light control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lightsOn = 0;
  int roomTemp = 70;
  
  printf("Welcome to your Smart Home Light Control!\n");

  while(1) {
    printf("\nEnter a command: ");
    char command[10];
    scanf("%s", command);
    
    if(strcmp(command, "on") == 0) {
      lightsOn = 1;
      printf("Lights on!\n");
    }
    else if(strcmp(command, "off") == 0) {
      lightsOn = 0;
      printf("Lights off!\n");
    }
    else if(strcmp(command, "temp") == 0) {
      printf("Current temperature is %d degrees Fahrenheit\n", roomTemp);
    }
    else if(strcmp(command, "warmer") == 0) {
      roomTemp += 5;
      printf("Temperature increased by 5 degrees!\n");
    }
    else if(strcmp(command, "cooler") == 0) {
      roomTemp -= 5;
      printf("Temperature decreased by 5 degrees!\n");
    }
    else if(strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      exit(0);
    }
    else {
      printf("Invalid command. Please try again.\n");
    }
    
    if(lightsOn && roomTemp > 75) {
      printf("***Warning: Room is too hot and lights are on!***\n");
    }
  }
  
  return 0;
}