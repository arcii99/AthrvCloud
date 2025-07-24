//FormAI DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include<stdio.h>
#include<math.h>

int main(){
  float g = 9.81;
  float angle, velocity, height, time;
  float x, y;
  printf("Enter the angle in degrees: ");
  scanf("%f", &angle);
  printf("Enter the velocity in m/s: ");
  scanf("%f", &velocity);
  printf("Enter the height in m: ");
  scanf("%f", &height);
  
  //convert angle to radians
  angle = angle * M_PI / 180;
  
  //calculate time of flight
  time = (2 * velocity * sin(angle)) / g;
  
  //calculate max height
  float max_height = height + (pow(velocity*sin(angle),2)/(2*g));
  
  printf("Time of flight: %.2f seconds\n", time);
  printf("Max height: %.2f meters\n\n\n", max_height);
  
  printf("Trajectory: \n");
  printf("Time\tX\tY\n");
  for(float t=0; t<=time; t+=0.01){
    x = velocity*cos(angle)*t;
    y = height + velocity*sin(angle)*t - 0.5*g*t*t;
    printf("%0.2f\t%0.2f\t%0.2f\n", t, x, y);
  }
  
  return 0;
}