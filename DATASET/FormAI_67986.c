//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>

int main(){
  char word[1000];
  int start, end, length;
  int is_palindrome = 1; 
  
  printf("Enter a word to check if it's a palindrome:\n");
  scanf("%s", word); 
  
  length = strlen(word); 
  end = length - 1;
  
  // loop to check if the word is a palindrome
  for (start = 0 ; start < length / 2 ; start++){
    if (word[start] != word[end]){
      is_palindrome = 0;
      break;
    }
    
    end--;
  }
  
  if (is_palindrome){
    printf("%s is a palindrome!", word);
  }
  else{
    printf("%s is not a palindrome :(", word);
  }
  
  return 0;
}