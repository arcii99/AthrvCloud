//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
  char name[50]; 
  char message[100] = "Hello "; 

  printf("What is your name?\n"); 
  scanf("%s", name); 

  strcat(message, name); 

  int length = strlen(name); 
  int i; 

  for(i = 0; i < length; i++) {
    char letter = name[i]; 

    if(letter >= 97 && letter <= 122) {
      letter -= 32; 
      printf("%c", letter); 
    }
    else if(letter >= 65 && letter <= 90) {
      letter += 32; 
      printf("%c", letter); 
    }
  }

  printf(", you have %d letters in your name!\n", length); 
  printf("%s\n", message); 

  return 0; 
}