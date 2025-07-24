//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  int length, i;
  char password[100];
  srand(time(NULL));
  
  printf("Oh, sweet password generator, what shall thy length be?: ");
  scanf("%d", &length);
  
  printf("\nAh, thy length has been set to %d.\n\nThe code to your heart is:\n", length);
  
  for (i = 0; i < length; i++) {
    int random = rand() % 6; // generate a random integer between 0 and 5
    
    switch (random) {
      case 0: // uppercase letter
        password[i] = rand() % 26 + 65; // generate a random integer between 65 and 90, which corresponds to ASCII uppercase letters
        break;
        
      case 1: // lowercase letter
        password[i] = rand() % 26 + 97; // generate a random integer between 97 and 122, which corresponds to ASCII lowercase letters
        break;
        
      case 2: // number
        password[i] = rand() % 10 + 48; // generate a random integer between 48 and 57, which corresponds to ASCII numbers
        break;
        
      case 3: // special character
        password[i] = rand() % 15 + 33; // generate a random integer between 33 and 47, which corresponds to ASCII special characters
        break;
        
      case 4: // more special characters
        password[i] = rand() % 7 + 58; // generate a random integer between 58 and 64, which corresponds to more ASCII special characters
        break;
        
      case 5: // even more special characters
        password[i] = rand() % 6 + 91; // generate a random integer between 91 and 96, which corresponds to even more ASCII special characters
        break;
    }
  }
  
  printf("%s\n\nA rose by any other name would smell as sweet, but this password shall not change: %s\n", password, password);
  
  return 0;
}