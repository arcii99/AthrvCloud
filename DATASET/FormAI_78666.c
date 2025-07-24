//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main(){
  //declare variables
  float temp, avg_temp = 0;
  int count = 0;
  
  //ask user for input
  printf("Please enter the temperature in celsius (enter -999 to exit): \n");

  //loop until user enters -999
  while(temp != -999){
    scanf("%f", &temp);
    
    //check if valid input
    if(temp > -273.15){
      avg_temp += temp;
      count++;
    }
    else{
      printf("Invalid temperature entered. Please try again.\n");
    }
  }
 
  //calculate average temperature
  if(count > 0){
    avg_temp /= count;
    printf("The average temperature is %.2f degrees Celsius.\n", avg_temp);
  }
  else{
    printf("No valid temperatures entered.\n");
  }
  
  return 0;
}