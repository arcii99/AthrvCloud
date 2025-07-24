//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main(){
  char input[100];
  printf("Please enter a text: "); 
  fgets(input, 100, stdin); //Taking input from user
  printf("Morse code: ");
  
  //Defining Morse code dictionary using nested arrays
  char *morse[36][2] = {
    {"A", ".-"},
    {"B", "-..."},
    {"C", "-.-."},
    {"D", "-.."},
    {"E", "."},
    {"F", "..-."},
    {"G", "--."},
    {"H", "...."},
    {"I", ".."},
    {"J", ".---"},
    {"K", "-.-"},
    {"L", ".-.."},
    {"M", "--"},
    {"N", "-."},
    {"O", "---"},
    {"P", ".--."},
    {"Q", "--.-"},
    {"R", ".-."},
    {"S", "..."},
    {"T", "-"},
    {"U", "..-"},
    {"V", "...-"},
    {"W", ".--"},
    {"X", "-..-"},
    {"Y", "-.--"},
    {"Z", "--.."},
    {"0", "-----"},
    {"1", ".----"},
    {"2", "..---"},
    {"3", "...--"},
    {"4", "....-"},
    {"5", "....."},
    {"6", "-...."},
    {"7", "--..."},
    {"8", "---.."},
    {"9", "----."},
  };
  
  //Loop through each character in input
  for(int i = 0; i < strlen(input); i++){
    char c = input[i];
    if(c >= 'a' && c <= 'z') c = c - 32; //Converts lowercase to uppercase
    if(c >= 'A' && c <= 'Z'){
      int index = c - 'A'; //Calculating index of current character
      printf("%s ", morse[index][1]); //Printing corresponding Morse code
    }else if(c >= '0' && c <= '9'){
      int index = c - '0' + 26; //Calculating index of current character
      printf("%s ", morse[index][1]); //Printing corresponding Morse code
    }else if(c == ' '){
      printf(" "); //Adding a space after each word
    }else{
      printf("? "); //If character is not in dictionary, print '?'
    }
  }
  return 0;
}