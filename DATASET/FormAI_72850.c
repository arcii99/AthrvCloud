//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int main(){

  int arrivalTime[5] = {10, 15, 20, 25, 30};
  int n = sizeof(arrivalTime)/sizeof(arrivalTime[0]);
  int i, j, t, temp;
  char bags[] = {'A', 'B', 'C', 'D', 'E'};

  //Sorting arrivalTime
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
       if(arrivalTime[j]>arrivalTime[j+1]){
          t = arrivalTime[j];
          arrivalTime[j] = arrivalTime[j+1];
          arrivalTime[j+1] = t;
          
          //Arranging bags according to their arrival times
          temp = bags[j];
          bags[j] = bags[j+1];
          bags[j+1] = temp;
       }
    }
  }

  printf(" Arrival Time |  Bag Name   |\n");
  printf("------------------------------\n");

  for(i=0;i<n;i++){
    printf("     %d        |      %c      |\n", arrivalTime[i], bags[i]);
  }

  return 0;
}