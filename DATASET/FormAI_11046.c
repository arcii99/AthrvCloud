//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include<stdio.h>
#include<string.h>

// Function to convert character to Morse code
char* toMorse(char c){
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
    default: return "";
  }
}

int main(){
  char input[100];
  printf("Enter text to convert to Morse code: ");
  scanf("%[^\n]%*c", input); // read entire line of input

  int len = strlen(input);
  for(int i=0; i<len; i++){
    if(input[i] == ' '){
      printf(" / ");
      continue;
    }

    char* morse = toMorse(toupper(input[i])); // get Morse code equivalent
    if(strlen(morse) == 0){
      printf("%c", input[i]); // character is not a letter, print as is
    } else {
      printf("%s", morse);
      if(i != len-1 && input[i+1] != ' ')
        printf(" "); // add space between Morse letters
    }
  }

  return 0;
}