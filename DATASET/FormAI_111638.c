//FormAI DATASET v1.0 Category: Temperature monitor ; Style: retro
#include<stdio.h>

int main(){
  int temp, threshold = 30, time = 0, flag = 0;
  printf("\nWelcome to Retro Temperature Monitor\n");
  printf("Please enter the temperature in Celsius: ");
  scanf("%d", &temp);
  while(temp < 0){
    printf("Sorry, please enter a valid temperature: ");
    scanf("%d", &temp);
  }
  printf("\n");
  printf("Monitoring in progress...\n\n");
  printf("Temperature\tTime\n");
  printf("____________________\n");
  while(flag == 0){
    printf("%d\t\t%d seconds\n", temp, time);
    if(temp >= threshold){
      printf("\nWARNING: Temperature has exceeded the threshold!\n");
      flag = 1;
    }
    time += 10;
    temp += 1;
    if(temp == 45){
      temp = 20;
      time = 0;
    }
    if(time == 60){
      printf("\nSorry, the program has timed out. Monitoring stopped.\n");
      flag = 1;
    }
  }
  return 0;
}