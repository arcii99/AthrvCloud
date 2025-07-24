//FormAI DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char name[20] = "John";
  char adjective[10] = "surprised";
  
  strcat(name, " is ");
  
  char message[50];
  sprintf(message, "%s%s", name, adjective);
  
  int length = strlen(message);
  printf("Original message: %s\n", message);
  
  for(int i = 0; i < length; i++) {
    if(message[i] == 's') {
      message[i] = 'z';
    } else if(message[i] == 'd') {
      message[i] = 't';
    } else if(message[i] == 'r') {
      message[i] = 'l';
    } else if(message[i] == 'p') {
      message[i] = 'b';
    }
  }
  
  printf("Surprise! The new message is: %s\n", message);
  
  return 0;
}