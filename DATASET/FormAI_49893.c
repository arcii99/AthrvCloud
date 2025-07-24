//FormAI DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  int i, j, count = 0;

  printf("Enter your message: ");
  fgets(message, 100, stdin); // Scan in user message

  for(i = 0; message[i] != '\0'; i++) {
    if(message[i] == 'c') { // Look for instances of the letter 'c'
      for(j = i; message[j] != '\0'; j++) { // Iterate over the rest of the string
        if(message[j] == 'c') { // If another 'c' is found
          count++; // Increment the count
        }
      }
    }
  }

  if(count >= 3) { // If three or more instances of 'c' are found
    printf("Your message has been flagged as spam.\n");
  }
  else {
    printf("Your message is not spam.\n");
  }

  return 0;
}