//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countWords(char* str) { //function to count words in a string
  int count = 0;
  char* token;

  //strtok is used for tokenizing strings
  token = strtok(str, " "); //str is passed as first argument, " " space acts as delimeter in strtok

  while(token != NULL) { //when token is NULL, whole string has been tokenized
    count++;
    token = strtok(NULL, " "); //calling strtok again with str as NULL pointer starts tokenizing where strtok left off
  }

  return count;
}

int main() {
  char str[100];
  int wordNum;
  printf("Enter a sentence: ");
  fgets(str, 100, stdin); //fgets is used to get input of string type
  str[strlen(str)-1] = '\0'; //replace new line character of fgets with null character to remove error
  
  wordNum = countWords(str); //call the function countWords to get word count
  
  printf("The number of words are: %d", wordNum);
  
  return 0;
}