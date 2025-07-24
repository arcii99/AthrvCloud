//FormAI DATASET v1.0 Category: Math exercise ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

// Greetings
  printf("Welcome to the genius math exercise program!\n\n");
  printf("Today we will be solving an interesting math problem.\n\n");
  printf("Let's start with the problem statement:\n");
  printf("Given a set of numbers, find the number which is closest to their mean.\n\n");

// Initialisation
  int n;
  printf("Enter the number of elements you want to consider in the set: ");
  scanf("%d",&n);

  float arr[n];
  float sum = 0;
  
// Accepting Input Values
  printf("\nNow enter the numbers:\n");

  for(int i=0;i<n;++i){
    scanf("%f",&arr[i]);
    sum += arr[i];
  }
  
  float mean = sum/n;
  printf("\nThe mean of the numbers is: %f\n",mean);

// Finding the number closest to the mean
  float diff = fabs(mean-arr[0]);
  float closest_num = arr[0];

  for(int i=1;i<n;++i){
    float cur_diff = fabs(mean-arr[i]);
    if(cur_diff < diff){
      diff = cur_diff;
      closest_num = arr[i];
    }
  }

  printf("\nThe number closest to the mean is: %f",closest_num);
  
  return 0;
}