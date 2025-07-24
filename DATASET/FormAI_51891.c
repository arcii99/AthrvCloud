//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Unique C Compression Algorithm Program!\n");

  printf("Please enter the message you want to compress: ");
  char *message = (char *) malloc(sizeof(char) * 256); // allocate 256 bytes for message
  fgets(message, 256, stdin); // read message from user input
  message[strcspn(message, "\n")] = '\0'; // remove newline character from message

  int i, j, k, freq[256], x;
  char c[256], compressed[256] = "";
  memset(freq, 0, sizeof(freq)); // clear frequency array
  memset(c, 0, sizeof(c)); // clear character array

  for(i = 0; message[i] != '\0'; i++) {
    freq[(int) message[i]]++; // increment frequency of character in message
  }

  x = 0;
  for(i = 0; i < 256; i++) {
    if(freq[i] > 0) { // if character exists in message
      c[x] = (char) i; // add character to character array
      x++;
    }
  }

  for(i = 0; c[i] != '\0'; i++) {
    strcat(compressed, c[i]); // concatenate character to compressed string
    char freq_str[10]; // string to hold frequency of character
    sprintf(freq_str, "%d", freq[(int) c[i]]); // convert frequency to string
    strcat(compressed, freq_str); // concatenate frequency to compressed string
  }

  printf("\nThe original message: %s\n", message);
  printf("The compressed message: %s\n", compressed);

  free(message); // free memory allocated for message

  return 0;
}