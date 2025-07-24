//FormAI DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h> 

int main() { 
  char text[200]; 
  int i, word_count = 0, char_count = 0; 

  printf("Hello! Let's count your words and characters today. Please enter your text:\n"); 
  fgets(text, 200, stdin); 

  // Counting words 
  for(i=0;text[i]!='\0';i++) { 
    if(text[i]==' ' && text[i-1]!=' ') { 
      word_count++; 
    } 
  }
  if(text[0] != ' ') { // Edge case for first word 
    word_count++;
  }

  // Counting characters 
  for(i=0;text[i]!='\0';i++) { 
    if(text[i]!=' ' && text[i]!='\n') { 
      char_count++; 
    } 
  } 

  printf("\nHooray! We found %d words and %d characters from your text.\n", word_count, char_count); 
  printf("Keep up the good mood!\n"); 

  return 0; 
}