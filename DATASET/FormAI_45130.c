//FormAI DATASET v1.0 Category: String manipulation ; Style: content
#include<stdio.h>
#include<string.h>

int main() {
  char input_string[100]; //declaring a character array to store the input string
  printf("Enter a string: ");
  fgets(input_string, 100, stdin); //using fgets to read input and store in input_string

  printf("\nOriginal string: %s", input_string);

  //reversing the string
  int length = strlen(input_string);

  printf("\nReversed string: ");
  for(int i=length-1; i>=0; i--) {
    printf("%c", input_string[i]);
  }

  //finding the number of vowels and consonants in the string
  int vowels=0, consonants=0;
  for(int i=0; i<length; i++) {
    char ch = input_string[i];
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
       ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
      vowels++;
    }
    else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
      consonants++;
    }
  }

  printf("\nNumber of vowels: %d", vowels);
  printf("\nNumber of consonants: %d", consonants);

  //converting the string to uppercase
  printf("\nUppercase string: ");
  for(int i=0; i<length; i++) {
    char ch = input_string[i];
    if(ch>='a' && ch<='z') {
      ch = ch - 32;
    }
    printf("%c", ch);
  }

  //converting the string to lowercase
  printf("\nLowercase string: ");
  for(int i=0; i<length; i++) {
    char ch = input_string[i];
    if(ch>='A' && ch<='Z') {
      ch = ch + 32;
    }
    printf("%c", ch);
  }

  return 0;
}