//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
  int n, count = 0;
  printf("Enter the length of the password: ");
  scanf("%d", &n);
  
  // Check if user input is valid
  if(n < 8) {
    printf("Password too short. Please enter a length of 8 or more.");

    // Exit program
    return 0;
  }
  
  // Initialize seed for random number generation
  srand(time(0));
  
  // Generate random password using ASCII characters
  while(count < n) {
    int num = rand()%94 + 33;

    // Exclude special characters like single quote, double quote and backslash
    if(num == 39 || num == 34 || num == 92)
      continue;

    // Exclude similar looking characters like upper case I, lower case L and number 1
    if(num == 73 || num == 108 || num == 49)
      continue;

    // Exclude similar looking characters like upper case O and number 0
    if(num == 79 || num == 48)
      continue;

    char c = (char) num;

    printf("%c", c);
    count++;
  }
  
  printf("\n");
  return 0;
}