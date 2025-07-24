//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include<stdio.h>

int main() {
  int a, b, c; //declaring three integer variables
  printf("Enter password: "); //prompting user for input
  scanf("%d", &a); //reading user input and storing in 'a' variable
  
  if (a == 1234) { //checking if password is correct
    printf("Access granted.\n"); //displaying message
    printf("Enter number between 1 and 10: "); //prompting user for input
    scanf("%d", &b); //reading user input and storing in 'b' variable
    
    if (b == 7) { //checking if number is correct
      printf("Level 1 authentication complete.\n"); //displaying message
      printf("Enter name: "); //prompting user for input
      char name[50]; //declaring char array with size 50
      scanf("%s", name); //reading user input and storing in 'name' array
      
      if (name[0] == 'A' && name[1] == 'L' && name[2] == 'I' && name[3] == 'C' && name[4] == 'E') { //checking if name is correct
        printf("Level 2 authentication complete.\n"); //displaying message
        printf("Enter secret code: "); //prompting user for input
        scanf("%d", &c); //reading user input and storing in 'c' variable
        
        if (c == 987654321) { //checking if code is correct
          printf("Access granted.\n"); //displaying message
        } else { //if code is incorrect
          printf("Invalid secret code. Attempt failed.\n"); //displaying message
        }
        
      } else { //if name is incorrect
        printf("Invalid name. Attempt failed.\n"); //displaying message
      }
      
    } else { //if number is incorrect
      printf("Invalid number. Attempt failed.\n"); //displaying message
    }
    
  } else { //if password is incorrect
    printf("Invalid password. Attempt failed.\n"); //displaying message
  }
  
  return 0; //exiting program
}