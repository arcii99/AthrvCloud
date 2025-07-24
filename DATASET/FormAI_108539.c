//FormAI DATASET v1.0 Category: Physics simulation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

  int i,j;
  float velocity=0.0,accel=0.0,distance=0.0,traveltime=0.0;
  float acceleration1, acceleration2, time1, time2, distance1, distance2;
  
  printf("*******************************************************\n");
  printf("\t    Welcome to the Drag Racing Simulation!\n");
  printf("*******************************************************\n\n");
  printf("Let's determine the winner of the race based on the physics!\n");

  //Generating Random Acceleration Values for Two Cars
  srand(time(0));
  acceleration1 = ((float)rand()/RAND_MAX) * 50.0;
  acceleration2 = ((float)rand()/RAND_MAX) * 50.0;

  printf("\nCar 1 acceleration: %.2f m/s^2", acceleration1);
  printf("\nCar 2 acceleration: %.2f m/s^2\n", acceleration2);

  //Calculating Time Taken to Travel Distance of 400M
  distance1=400.0;
  distance2=400.0;
  
  for(i=1;distance1>=0.0 || distance2>=0.0;i++){

  time1=velocity/acceleration1 + traveltime;
  time2=velocity/acceleration2 + traveltime;

  distance1=400.0 - 0.5 * acceleration1 * time1 * time1;
  distance2=400.0 - 0.5 * acceleration2 * time2 * time2;

  if(distance1<=0.0 && distance2<=0.0){
    printf("Both Cars reached the finish line at the same time\n");
    break;
  }
  else if(distance1<=0.0){
    printf("Congratulations Car 1 has won the Race!\n");
    break;
  }
  else if(distance2<=0.0){
    printf("Congratulations Car 2 has won the Race!\n");
    break;
  }

  //Increasing Velocity based on Acceleration
  velocity=velocity + accel*time1;
  accel=acceleration1;
  traveltime=time1;
}
  return 0;
}