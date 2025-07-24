//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define THRESHOLD 10 //Threshold value to detect intrusion
#define BUFFER_SIZE 100 //Size of the buffer for storing messages

int main(){
  int counter = 0; // variable to count the number of failed login attempts
  char buffer[BUFFER_SIZE]; // buffer to store messages
  while(1){ // infinite loop for continuously monitoring the system
    printf("Enter username: ");
    scanf("%s", buffer); // reading the username from the user
    if(strcmp(buffer, "admin") == 0){ // checking if the entered username is 'admin'
      printf("Enter password: ");
      scanf("%s", buffer); // reading the password from the user
      
      if(strcmp(buffer, "password") != 0){ // checking if the entered password is incorrect
        counter++; // incrementing the failed login attempt counter
        printf("Incorrect password. %d failed attempts.\n", counter);
        if(counter >= THRESHOLD){ // checking if the threshold value has been reached
          printf("INTRUSION DETECTED!! Locking system...\n");
          exit(0); // terminating the program after detecting intrusion
        }
      }
      else{ // when the password is correct
        printf("Login successful!\n");
        counter = 0; // resetting the failed login attempt counter
      }
    }
    else{ // if the entered username is not 'admin'
      printf("Invalid username.\n");
    }
  }
  return 0;
}