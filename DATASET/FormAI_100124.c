//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include<stdio.h>
#include<string.h>

int main(){
  
  char input[1000]; //declare an array to store user input
  int count_C = 0; //initialize count for 'C'

  printf("Enter a string: ");
  fgets(input, 1000, stdin); //get user input

  for(int i = 0; i < strlen(input); i++){ //loop through each character in the input string
    if(input[i] == 'C' || input[i] == 'c'){ //if the character is 'C' or 'c'
      count_C++; //increment the count
    }
  }

  printf("The count of 'C' in your string is: %d\n", count_C); //output the count

  return 0;
}