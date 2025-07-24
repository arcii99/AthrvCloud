//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>

int is_prime(int num){
  int i;
  for(i=2; i<=num/2;i++){
    if(num%i==0){
      return 0;
    }
  }
  return 1;
}

void prime_generator(int n){
  int i,count=0,num=2;

  while(count<n){
    if(is_prime(num)){
      printf("%d ",num);
      count++;
    }
    num++;
  }
}

int main(){
  int n;

  printf("Enter the number of primes you want to generate: ");
  scanf("%d", &n);

  printf("%d prime numbers are: \n",n);
  prime_generator(n);

  return 0;
}