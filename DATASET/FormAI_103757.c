//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main()
{
  char text[100];
  
  printf("Enter some text: ");
  fgets(text, 100, stdin);
  
  // Remove any newline character at end of input
  text[strcspn(text, "\n")] = 0;
  
  int num_words = 0;
  int num_vowels = 0;
  int num_consonants = 0;
  
  // Loop through each character in input text
  for(int i=0; i<strlen(text); i++)
  {
    // If current character is a letter
    if(isalpha(text[i]))
    {
      // Increment count of vowels or consonants
      if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
        num_vowels++;
      else
        num_consonants++;
      
      // If previous character was not a letter, increment word count
      if(i > 0 && !isalpha(text[i-1]))
        num_words++;
    }
  }
  
  // If last character was a letter, increment word count
  if(isalpha(text[strlen(text)-1]))
    num_words++;
  
  printf("Number of words: %d\n", num_words);
  printf("Number of vowels: %d\n", num_vowels);
  printf("Number of consonants: %d\n", num_consonants);
  
  return 0;
}