//FormAI DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char message[100];
  int count = 0;
  
  printf("Enter your message: ");
  fgets(message, 100, stdin);
  
  for(int i = 0; message[i] != '\0'; i++)
  {
    if(message[i] == 'c' && message[i+1] == 'a' && message[i+2] == 't')
    {
      count++;
      i+=2; //skip the remaining characters of 'cat'
    }
    if(count >= 3)
    {
      printf("This message is likely spam.\n");
      return 0;
    }
  }
  
  printf("This message is not spam.\n");
  
  return 0;
}