//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char greetings[] = "Hello, World!";
  char name[20];
  
  printf("%s\n", greetings); // print the greetings

  printf("What is your name?\n");
  scanf("%s", name); // read name from user input

  strcat(greetings, " Nice to meet you, "); // concatenate strings
  strcat(greetings, name);
  printf("%s\n", greetings); // print the greetings with the name
  
  printf("Let's do some string manipulation!\n");

  printf("The length of the greetings string is: %lu\n", strlen(greetings)); // print the length of the greetings string

  char upper_greetings[strlen(greetings) + 1]; // create new string with same length as greetings
  for(int i = 0; i < strlen(greetings); i++){
    upper_greetings[i] = toupper(greetings[i]); // convert every character to uppercase and store in upper_greetings
  }
  upper_greetings[strlen(greetings)] = '\0'; // add null terminator to the end of the string
  printf("%s\n", upper_greetings); // print the uppercase greetings
  
  char reverse_greetings[strlen(greetings) + 1]; // create new string with same length as greetings
  int count = 0;
  for(int i = strlen(greetings) - 1; i >= 0; i--){
    reverse_greetings[count] = greetings[i]; // reverse the order of characters in greetings and store in reverse_greetings
    count++;
  }
  reverse_greetings[strlen(greetings)] = '\0'; // add null terminator to the end of the string
  printf("%s\n", reverse_greetings); // print the reversed greetings

  char substring[strlen(name) + 1]; // create new string with same length as name
  for(int i = 0; i < strlen(name); i++){
    substring[i] = name[i + 1]; // copy all characters in name except for the first one and store in substring
  }
  substring[strlen(name)] = '\0'; // add null terminator to the end of the string
  printf("%s\n", substring); // print the substring

  return 0;
}