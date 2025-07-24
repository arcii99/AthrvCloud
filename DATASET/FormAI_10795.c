//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include<stdio.h>

int main(){

  printf("Welcome to the Prime Number Generator.\n");
  printf("Please enter the range in which you want to find the prime numbers\n");

  int start, end, flag, i, j;

  scanf("%d %d", &start, &end);

  printf("The Prime Numbers in the range from %d to %d are: \n", start, end);

  for (i = start; i <= end; i++) { 

      flag=0;
      for (j = 2; j <= i / 2; j++) {
          
          if ((i % j) == 0) {
              
            flag = 1;
            break;
          }
      }
        
        
    if (flag == 0 && i != 1){
          
        printf("%d\n", i);
          
      }
  }

 printf("Thank you for using Prime Number Generator.\n");
  return 0;
}