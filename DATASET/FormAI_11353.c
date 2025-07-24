//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  // Declare necessary variables
  const int PASSWORD_LENGTH = 12;  // Length of password
  char password[PASSWORD_LENGTH];  // Array to store password
  int random;                      // Random number generator
  int i;
  
  // Set seed for random number generator
  srand(time(NULL));
  
  // Generate random password using ASCII table
  for(i = 0; i < PASSWORD_LENGTH; i++){
    
    // Generate random number
    random = rand() % 74 + 48;
    
    // Ensure that character is alphanumeric or a special character
    while(!((random >= 48 && random <= 57) || (random >= 65 && random <= 90) || (random >= 97 && random <= 122) || (random >= 33 && random <= 47) || (random >= 58 && random <= 64) || (random >= 91 && random <= 96) || (random >= 123 && random <= 126))){
      random = rand() % 74 + 48;
    }
    
    // Store character in password array
    password[i] = random;
    
  }
  
  // Print generated password
  printf("Your secure password is: ");
  for(i = 0; i < PASSWORD_LENGTH; i++){
    printf("%c", password[i]);
  }
  printf("\n");
  
  // Exit program
  return 0;
}