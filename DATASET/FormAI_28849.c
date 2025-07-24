//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main(){

  //Greeting the user
  printf("Hello there! Let's check if your entered word or phrase is a palindrome!\n");

  //Declaring and initializing variables
  char word[100];
  int length, i, j, flag = 0;

  //Asking for user's input
  printf("Please enter a word or phrase: ");
  scanf("%[^\n]", word);

  //Getting length of the word/phrase
  length = strlen(word);

  //Checking for palindrome
  for(i=0, j=length-1; i<length/2; i++, j--){
    if(word[i] != word[j]){
      flag = 1;
      break;
    }
  }

  //Printing the result
  if(flag == 0)
    printf("Hooray! Your input is a palindrome! :)\n");
  else
    printf("Oh no! Your input is not a palindrome. :( \n");

  //Goodbye message
  printf("Thanks for using our palindrome checker! Have a nice day! :D\n");

  return 0;
}