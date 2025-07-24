//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include<stdio.h>
#include<string.h>

// Function that converts a character to its equivalent Morse code
char* charToMorse(char c){
  switch(c){
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    default: return "";
  }
}

// Function that converts a string to its Morse code equivalent
void stringToMorse(char *input){
  int length = strlen(input);
  // Iterating over each character in input and printing its equivalent Morse code
  for(int i=0;i<length;i++){
    char *morse = charToMorse(toupper(input[i]));
    if(strlen(morse)>0){
      printf("%s", morse);
    }
    printf(" ");
  }
  printf("\n");
}

// Main function that takes user input and calls stringToMorse
int main(){
  printf("Enter a string to convert to Morse code:\n");
  char input[100];
  fgets(input,100,stdin);
  printf("The Morse code for the input is:\n");
  stringToMorse(input);
  return 0;
}