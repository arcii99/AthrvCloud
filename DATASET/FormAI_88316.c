//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include<stdio.h>
#include<string.h>

/*
This program takes a string as input and checks if it is a palindrome. If it is a palindrome, it converts it to uppercase
and if it is not a palindrome, it converts it to lowercase.
*/

int main(){
  char inputString[100];
  int i, len, flag=0;
  
  printf("Enter a string: ");
  fgets(inputString, 100, stdin);
  
  len = strlen(inputString) - 1; //subtract 1 to exclude newline character
  
  //checking if the string is a palindrome
  for(i=0; i<len/2; i++){
    if(inputString[i] != inputString[len-i-1]){
      flag=1;
      break;
    }
  }
  
  if(flag==0){
    //if the string is a palindrome, convert it to uppercase
    for(i=0; i<len; i++){
      inputString[i] = toupper(inputString[i]);
    }
    printf("\nThe input string was a palindrome! Converted to uppercase: %s", inputString);
  }else{
    //if the string is not a palindrome, convert it to lowercase
    for(i=0; i<len; i++){
      inputString[i] = tolower(inputString[i]);
    }
    printf("\nThe input string was not a palindrome! Converted to lowercase: %s", inputString);
  }
  
  return 0;
}