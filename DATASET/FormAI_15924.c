//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define PASS_LENGTH 12
#define MAX_CHAR 93

char generateRandomChar(){
  char randomChar = 33 + (rand() % (MAX_CHAR));
  return randomChar;
}

int checkUpperCase(char password[]){
  for(int i=0; i<PASS_LENGTH; i++){
    if(isupper(password[i]))
      return 1;
  }
  return 0;
}

int checkLowerCase(char password[]){
  for(int i=0; i<PASS_LENGTH; i++){
    if(islower(password[i]))
      return 1;
  }
  return 0;
}

int checkNumeric(char password[]){
  for(int i=0; i<PASS_LENGTH; i++){
    if(isdigit(password[i]))
      return 1;
  }
  return 0;
}

int checkSpecialCharacter(char password[]){
  for(int i=0; i<PASS_LENGTH; i++){
    if(!isalnum(password[i]))
      return 1;
  }
  return 0;
}

void generatePassword(char password[]){
  char randomChar;
  int isUnique;
  for(int i=0; i<PASS_LENGTH; i++){
    isUnique = 0;
    while(!isUnique){
      randomChar = generateRandomChar();
      if(!strchr(password, randomChar)){
        password[i] = randomChar;
        isUnique = 1;
      }
    }
  }
  password[PASS_LENGTH] = '\0';
}

int main(){
  char password[PASS_LENGTH + 1];
  int isStrongPassword = 0, hasUpper = 0, hasLower = 0, hasNumber = 0, hasSpecialChar = 0;

  srand(time(NULL));

  while(!isStrongPassword){
    generatePassword(password);
    hasUpper = checkUpperCase(password);
    hasLower = checkLowerCase(password);
    hasNumber = checkNumeric(password);
    hasSpecialChar = checkSpecialCharacter(password);

    if(hasUpper && hasLower && hasNumber && hasSpecialChar)
      isStrongPassword = 1;
  }

  printf("Generated Password: %s", password);
  return 0;
}