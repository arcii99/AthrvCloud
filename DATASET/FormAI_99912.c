//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

char* generatePassword();

int main(){
  char* password;
  password = generatePassword();
  printf("Your secure password is: %s\n", password);
  free(password);
  return 0;
}

char* generatePassword(){
  char* password = (char*) malloc((PASSWORD_LENGTH + 1) * sizeof(char));
  srand(time(NULL));
  const char* lowerCase = "abcdefghijklmnopqrstuvwxyz";
  const char* upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char* digits = "0123456789";
  const char* specialChars = "!@#$%^&*()_+{}[]|;':\",./<>?";
  int i;
  int randomIndex;
  for(i = 0; i < PASSWORD_LENGTH; i++){
    randomIndex = rand() % 4;
    switch(randomIndex){
      case 0: // lower case letters
        password[i] = lowerCase[rand() % 26];
        break;
      case 1: // upper case letters
        password[i] = upperCase[rand() % 26];
        break;
      case 2: // digits
        password[i] = digits[rand() % 10];
        break;
      case 3: // special characters
        password[i] = specialChars[rand() % 29];
        break;
    }
  }
  password[PASSWORD_LENGTH] = '\0';
  return password;
}