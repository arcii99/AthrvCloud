//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temp[7][24];
  srand(time(NULL));
  
  //initialize temperature array with random values between -10 and 35
  for(int i=0; i<7; i++){
    for(int j=0; j<24; j++){
      temp[i][j] = rand() % 46 - 10;
    }
  }
  
  //print average temperature for each day
  for(int i=0; i<7; i++){
    int sum = 0;
    for(int j=0; j<24; j++){
      sum += temp[i][j];
    }
    int avg = sum / 24;
    printf("Average temperature for Day %d: %d\n", i+1, avg);
  }
  
  //print hourly temperature for a given day
  int day;
  printf("Enter a day (1-7) to see hourly temperature:");
  scanf("%d", &day);
  
  printf("Hourly temperature for Day %d:\n", day);
  for(int i=0; i<24; i++){
    printf("%d:00 - %d:00 : %d\n", i, i+1, temp[day-1][i]);
  }
  
  return 0;
}