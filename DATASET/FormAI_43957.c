//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100000],word[100000]; //define string and word array with size 100000 for large inputs
  int count = 0, i; //initialize count to 0 and i for iteration
  
  printf("Enter a string:\n");
  fgets(str, 100000, stdin); //get the string input from user
  
  printf("Enter the word to count:\n");
  fgets(word, 100000, stdin); //get the word input from user
  
  for (i = 0; i < strlen(str); i++) { //iterate through the string
    if (strncmp(&str[i],word,strlen(word)) == 0) { //if the current element in string matches the word, increase count
      count++;
    }
  }
  
  printf("The count of the word '%s' in the string is: %d\n", word, count); //print the count

  return 0;
}