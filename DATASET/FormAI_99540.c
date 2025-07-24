//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand(time(NULL)); // Seeding for randomness
  char password[15];
  int length; 
  printf("Welcome to Password Management System!\n");
  printf("Please enter the length of your desired password: ");
  scanf("%d",&length);
  
  if(length<8){ // Minimum password length of 8
    printf("Aren't you feeling a bit insecure? Please enter at least 8 characters.\n");
    printf("Please enter the length of your desired password: ");
    scanf("%d",&length);
  }
  
  printf("Great! Generating a password for you now.\n");

  char specialChars[] = {'!','@','#','$','%','^','&','*','(',')','-','+','=','{','}','[',']','|','\\',':',';','<','>','.',',','?'};
  
  int numSpecialChars = sizeof(specialChars)/sizeof(specialChars[0]); 
  
  for(int i=0;i<length;i++){
    int r = rand() % 3; // Generating a random number between 0 and 2 inclusive
    switch(r){
      case 0:
        password[i] = 'a' + rand()%26; // Generating a random lowercase letter
        break;
      case 1:
        password[i] = 'A' + rand()%26; // Generating a random uppercase letter
        break;
      case 2:
        password[i] = specialChars[rand()%numSpecialChars]; // Generating a random special character
        break;
    }
  }
  
  printf("Your new password is: ");
  
  for(int i=0;i<length;i++) printf("%c",password[i]); // Print the password
  
  printf("\n");
  
  return 0;
}