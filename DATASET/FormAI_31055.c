//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  printf("Welcome to the Prime Number generator in C!\n");
  
  int counter = 0;
  
  for(int i = 2; ; i++){
    int prime = 1;
    
    for(int j = 2; j <= i / 2; j++){
      if(i % j == 0){
        prime = 0;
        break;
      }
    }
    
    if(prime == 1){
      printf("%d ", i);
      counter++;
    }
    
    if(counter == 10){
      printf("\n");
      counter = 0;
    }
  }
  
  return 0;
}