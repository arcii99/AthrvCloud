//FormAI DATASET v1.0 Category: Pattern printing ; Style: unmistakable
//This program prints a unique pattern using C language.
#include <stdio.h>

int main(){

  int i, j, k;

  //Upper half of the pattern.
  for(i=1; i<=5; i++){
    for(j=5; j>i; j--){
      printf(" ");
    }
    printf("*");
    for(k=1; k<(i-1)*2; k++){
      printf(" ");
    }
    if(i>1){
      printf("*");
    }
    printf("\n");
  }

  //Lower half of the pattern.
  for(i=4; i>=1; i--){
    for(j=5; j>i; j--){
      printf(" ");
    }
    printf("*");
    for(k=1; k<(i-1)*2; k++){
      printf(" ");
    }
    if(i>1){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

/*
Explanation:
The above code uses 3 nested for loops to print the pattern.
The first for loop is for the number of rows.
The second for loop is to print the spaces before the first star.
The third for loop is to print the spaces between the two stars.

Output:

    *
   * *
  *   *
 *     *
*       *
*       *
 *     *
  *   *
   * *
    *

*/