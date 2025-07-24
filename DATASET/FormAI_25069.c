//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

int recursive_solitude(int num) { 
  if(num == 1) 
    return 1; 
  else if(num == 2) 
    return 1; 
  else
    return recursive_solitude(num - 1) + recursive_solitude(num - 2); 
} 

int main() { 
  int integer_input, i = 1; 
  printf("Greetings, dear User!\n"); 
  printf("What integer would you like to use? "); 
  scanf("%d", &integer_input); 

  printf("\nHere is the perfect recursive pattern for %d:\n", integer_input); 

  while(i <= integer_input) { 
    printf("%d ", recursive_solitude(i)); 
    i++; 
  } 
  
  printf("\nThank you for computing with us.\n"); 
  return 0; 
}