//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 100

int main(void) 
{
  char text[MAX_LEN];
  int i = 0;
  bool sentenceStart = true;
  int  sentenceCount = 0;
  
  printf("Enter text: ");
  fgets(text, MAX_LEN, stdin);

  while (text[i] != '\0') 
  {
    if (sentenceStart && isalpha(text[i])) 
    {
      sentenceStart = false;
      sentenceCount++;
    } 
    else if (text[i] == '.' || text[i] == '!' || text[i] == '?') 
    {
      sentenceStart = true;
    }
    i++;
  }
  
  printf("Sentence count: %d\n", sentenceCount);
  
  return 0;
}