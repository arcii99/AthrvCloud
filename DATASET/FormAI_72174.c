//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include<stdio.h>

int main(){
  int n, i, j, isPrime;
  
  printf("Enter the value of n: ");
  scanf("%d", &n);
  
  printf("The first %d prime numbers are: ", n);
  
  // handling first 2 prime numbers
  printf("2 ");
  
  // checking for odd prime numbers
  for(i=3; i<=n; i++){
    isPrime = 1; // setting isPrime to true
    
    // checking if i is prime
    for(j=2; j<=i/2; j++){
      if(i%j == 0){
        isPrime = 0; // setting isPrime to false
        break;
      }
    }
    
    // printing prime numbers
    if(isPrime == 1){
      printf("%d ", i);
    }
  }
  
  return 0;
}