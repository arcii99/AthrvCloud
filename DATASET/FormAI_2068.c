//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>

int is_prime(int num){
  if(num <= 1){
    return 0;
  }
  for(int i=2;i<num;i++){
    if(num%i==0){
      return 0;
    }
  }
  return 1;
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  
  if(is_prime(num)){
    printf("%d is a prime number.\n", num);
  }else{
    printf("%d is not a prime number.\n", num);
  }
  
  printf("Prime numbers till %d are:\n", num);
  for(int i=2;i<=num;i++){
    if(is_prime(i)){
      printf("%d ",i);
    }
  }
  return 0;
}