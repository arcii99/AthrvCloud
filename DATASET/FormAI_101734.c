//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  printf("Enter a message: ");
  fgets(message, sizeof(message), stdin);
  
  int count = 0;
  for (int i=0; i<strlen(message); i++) {
    if (message[i] >= 'a' && message[i] <= 'z') { 
      message[i] = message[i] - 'a' + 'A'; //convert to uppercase
      count++;
    }
  }
  
  printf("Your message in all caps: %s", message);
  printf("Number of lowercase letters converted to uppercase: %d\n", count);
  
  return 0;
}