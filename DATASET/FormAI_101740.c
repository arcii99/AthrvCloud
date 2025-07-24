//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include <stdio.h>
#include <string.h>

int main(){
  char str[100];
  printf("Hello there! I am a palindrome checker.\n");
  printf("I can tell you if a word or phrase reads the same forwards and backwards.\n");
  printf("Please enter a word/phrase for me to check: ");
  fgets(str, 100, stdin);
  
  // Remove new line character from string
  if(str[strlen(str)-1] == '\n') {
     str[strlen(str)-1] = '\0';
  }
  
  // Ignore spaces in string
  char new_str[100];
  int j = 0;
  for(int i = 0; i < strlen(str); i++){
    if(str[i] != ' '){
      new_str[j] = str[i];
      j++;
    }
  }
  new_str[j] = '\0';
  
  // Check if string is a palindrome
  int len = strlen(new_str);
  int is_palindrome = 1;
  for(int i = 0; i < len/2; i++){
    if(new_str[i] != new_str[len-i-1]){
      is_palindrome = 0;
      break;
    }
  }
  
  // Output results
  if(is_palindrome){
    printf("Wow! \"%s\" is a palindrome! You sure know how to pick 'em!\n", str);
  } else {
    printf("Sorry, \"%s\" is not a palindrome. Maybe try again with a better word/phrase?\n", str);
  }
  
  printf("Thanks for checking with me. Have a palindrome-filled day! :)\n");
  return 0;
}