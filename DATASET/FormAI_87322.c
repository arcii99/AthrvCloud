//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int recursiveRandom(int min, int max){
    if (min == max){
        return min;
    }
    int range = (max - min) + 1; 
    int rand_num = rand() % range + min;
    printf("%d\n", rand_num);
    return recursiveRandom(min, max);
}

int main(){
  srand(time(NULL));
  int min, max;
  printf("Enter minimum and maximum range: ");
  scanf("%d %d", &min, &max);
  if (min > max){
      printf("Invalid range\n");
      exit(0);
  }
  recursiveRandom(min, max);
  return 0;
}