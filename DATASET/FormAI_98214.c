//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
  if(num < 2){
    return false;
  }
  for(int i=2; i*i<=num; i++){
    if(num%i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int n; // number of prime numbers to generate
  printf("Enter the number of prime numbers to generate: ");
  scanf("%d", &n);
  
  int count = 0; // counter for prime numbers generated
  int num = 2; // starting number
  printf("The first %d prime numbers are:\n", n);
  while(count < n){
    if(isPrime(num)){
      printf("%d ", num);
      count++;
    }
    num++;
  }
  return 0;
}