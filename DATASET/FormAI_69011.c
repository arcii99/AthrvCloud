//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Declare the function to decode the Alien language message
void decode_message(char message[], int message_len);

// The main function
int main(void) {
  // Example Alien language message
  char alien_message[] = "1010011101100010011001010100001110001001";
  int message_len = strlen(alien_message);
 
  printf("Original Message : %s\n", alien_message);
  
  // Call the decode function
  decode_message(alien_message, message_len);

  return 0;
}

// Function definition to decode the Alien language message
void decode_message(char message[], int message_len) {
  // Initialize the variables
  int i, j;
  char decoded_message[message_len/5];
  int decimal_val;
  int power = 1;
  int k = 0;

  // Decode the message using ASCII values 
  for(i=message_len-1; i>=0; i-=5) {
    decimal_val = 0;
    power = 1;
    for(j=0; j<5; j++) {
      if(message[i-j] == '1') {
        decimal_val += power;
      }
      power *= 2;
    }
    decoded_message[k++] = decimal_val + 96; // ASCII value of lowercase a is 97
  }

  // Reverse the decoded message to get the correct order
  for(i=k-1; i>=0; i--) {
    printf("%c", decoded_message[i]);
  }
  
  printf("\n");
}