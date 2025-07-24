//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include<stdio.h>
#include<stdlib.h>

// Function to turn on light
void turnOn(){
  printf("Lights turned on!\n");
}

// Function to turn off light
void turnOff(){
  printf("Lights turned off!\n");
}

int main(){
  int choice;
  printf("Welcome to Smart Home Light Control System\n");
  printf("1. Turn On Lights\n");
  printf("2. Turn Off Lights\n");
  printf("3. Exit\n\n");
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1: 
        turnOn();
        break;
      case 2:
        turnOff();
        break;
      case 3:
        printf("Goodbye!\n");
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }
  return 0;
}