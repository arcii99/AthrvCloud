//FormAI DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float current_temperature;
  char response;

  printf("Welcome to Temperature Monitor. \n");

  do {
    printf("Please enter the current temperature in Celsius: ");
    scanf("%f", &current_temperature);

    if(current_temperature >= 25.0) {
      printf("It is hot!\n");
    }
    else if(current_temperature >= 20.0) {
      printf("It is warm.\n");
    }
    else if(current_temperature >= 10.0) {
      printf("It is cool.\n");
    }
    else {
      printf("It is cold!\n");
    }
    
    printf("Would you like to enter another temperature? (Y/N): ");
    scanf(" %c", &response);

  } while(response == 'Y' || response == 'y');

  printf("Thank you for using Temperature Monitor. Goodbye!");

  return 0;
}