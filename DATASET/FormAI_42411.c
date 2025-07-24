//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 10000000
#define MAX_ITER 1000000

int main(){
  
  // Surrealism meets performance-critical programming
  // The following program generates a random array of integers
  // and then sorts it using a very peculiar method.

  int arr[MAX_NUM];
  
  srand(time(0));
  
  for(int i=0;i<MAX_NUM;i++)
    arr[i] = rand();
  
  printf("Sorting the array using surreal sorting algorithm...\n");
  
  int i=MAX_NUM-1,j=0,k=0;
  
  clock_t t1,t2;
  
  t1 = clock();
  while(j<MAX_ITER){
    while(k<MAX_ITER/i){
      arr[k] = arr[k]^arr[i-k];
      arr[i-k] = arr[i-k]^arr[k];
      arr[k] = arr[k]^arr[i-k];
      k++;
    }
    k=0;
    j++;
    if(i>0)
      i --;
    else
      i = MAX_NUM-1;
  }
  t2 = clock();

  printf("Finished sorting.\n");
  printf("Elapsed time: %f seconds.\n", (double)(t2-t1)/CLOCKS_PER_SEC);
  
  return 0;
}