//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Let's print a cool pattern in C!\n");
  
  // First part of the pattern
  for(int i=1; i<=10; i++){
    for(int j=1; j<=i; j++){
      printf("*");
    }
    printf("\n");
  }
  
  // Second part of the pattern
  for(int i=10; i>=1; i--){
    for(int j=1; j<=i; j++){
      printf("*");
    }
    printf("\n");
  }
  
  // Third part of the pattern
  for(int i=1; i<=10; i++){
    for(int j=1; j<=i; j++){
      printf(" ");
    }
    for(int k=10; k>=i; k--){
      printf("*");
    }
    printf("\n");
  }
  
  // Final part of the pattern
  for(int i=10; i>=1; i--){
    for(int j=1; j<=i; j++){
      printf(" ");
    }
    for(int k=10; k>=i; k--){
      printf("*");
    }
    printf("\n");
  }
  
  printf("Woohoo! We printed a cool pattern in C!\n");

  return 0;
}