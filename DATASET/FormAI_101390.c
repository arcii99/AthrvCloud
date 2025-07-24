//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int a = 4;
  int b = 8;
  int c = a + b;
  float x = 3.14;
  float y = 2.72;
  float z = x + y;

  printf("Welcome to the Physics Simulation Program!\n\n");
  printf("In this program, we will simulate the motion of a pendulum.\n");
  printf("We will assume that the pendulum is perfectly rigid and that the string is massless.\n");
  printf("We will also assume that the pendulum is subject only to gravity.\n");
  printf("Please enter the length of the string in meters: ");

  float L = 0;
  scanf("%f", &L);
  
  float g = 9.8; // gravitational constant
  float T = 0; // period of oscillation
  float T1 = 0; // time for one complete cycle
  float T2 = 0; // time for half a cycle
  float theta = 0; // maximum displacement of the pendulum
  
  theta = asin(L); // theta is the angle between the vertical and the string
  T1 = 2 * M_PI * sqrt(L/g); // T1 is the time for one complete cycle
  T2 = T1 / 2; // T2 is the time for half a cycle
  T = T2 * (sqrt(1 + pow(sin(theta/2),2))/2); // T is the period of oscillation
  
  printf("\nThe period of oscillation is %.2f seconds.\n", T);
  printf("The time for one complete cycle is %.2f seconds.\n", T1);
  printf("The time for half a cycle is %.2f seconds.\n", T2);
  printf("The maximum displacement of the pendulum is %.2f degrees.\n", theta * (180/M_PI));

  return 0;
}