//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  printf("Welcome to the Color Code Converter!\n");
  printf("Please enter the color code (RGB format): ");

  char input[7];
  fgets(input, 8, stdin);

  int Red, Green, Blue;
  
  sscanf(input, "%02x%02x%02x", &Red, &Green, &Blue);
  
  printf("The converted color code is: \n");
  printf("Red: %d \n", Red);
  printf("Green: %d \n", Green);
  printf("Blue: %d \n", Blue);

  return 0;
}