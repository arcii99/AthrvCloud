//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // seed the random number generator
  
  char password[13]; // allocate space for password
  int i, random_num;
  
  // Generate random password
  for(i = 0; i < 12; i++){
    random_num = rand() % 62; // generate number between 0-61 inclusive
    if(random_num < 26) { // if random number is less than 26, add uppercase letter to password
      password[i] = 'A' + random_num;
    } else if (random_num < 52) { // if random number is between 26-51, add lowercase letter to password
      password[i] = 'a' + (random_num - 26);
    } else { // if random number is between 52-61, add number to password
      password[i] = '0' + (random_num - 52);
    }
  }
  password[12] = '\0'; // add null terminator to password string
  
  printf("Your secure password is: %s\n", password);
  
  return 0;
}