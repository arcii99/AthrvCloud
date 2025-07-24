//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ephemeral
#include<stdio.h>
#include<string.h>

// A function to convert character to Morse code
void morse(char ch){
  switch(ch){
    case 'A': 
    printf(".-");
    break;
    case 'B':
    printf("-...");
    break;
    case 'C':
    printf("-.-.");
    break;
    case 'D':
    printf("-..");
    break;
    case 'E':
    printf(".");
    break;
    case 'F':
    printf("..-.");
    break;
    case 'G':
    printf("--.");
    break;
    case 'H':
    printf("....");
    break;
    case 'I':
    printf("..");
    break;
    case 'J':
    printf(".---");
    break;
    case 'K':
    printf("-.-");
    break;
    case 'L':
    printf(".-..");
    break;
    case 'M':
    printf("--");
    break;
    case 'N':
    printf("-.");
    break;
    case 'O':
    printf("---");
    break;
    case 'P':
    printf(".--.");
    break;
    case 'Q':
    printf("--.-");
    break;
    case 'R':
    printf(".-.");
    break;
    case 'S':
    printf("...");
    break;
    case 'T':
    printf("-");
    break;
    case 'U':
    printf("..-");
    break;
    case 'V':
    printf("...-");
    break;
    case 'W':
    printf(".--");
    break;
    case 'X':
    printf("-..-");
    break;
    case 'Y':
    printf("-.--");
    break;
    case 'Z':
    printf("--..");
    break;
    case ' ':
    printf("/");
    break;
    default:
    printf("%c", ch);
  }
}

void main(){
  char string[100];
  int length;
  int i;

  printf("Enter a text to convert to Morse code: \n");
  fgets(string, sizeof(string), stdin);

  length = strlen(string);

  printf("\nMorse code for entered text is: \n");

  // Loop through the entire string and convert each character to Morse code
  for(i=0; i<length; i++){
    morse(toupper(string[i]));
    printf(" ");
  }

  printf("\n");

  return 0;
}