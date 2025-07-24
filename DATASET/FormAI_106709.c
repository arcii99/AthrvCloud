//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main(){
  char text[100], morse[100]="";
  int i, j;
  printf("Welcome to the Text to Morse Code Converter!\n");
  printf("Enter your text to be converted:\n");
  fgets(text,100,stdin);
  printf("Your text is: %s\n", text);
  for(i=0; i<strlen(text); i++){
    switch(text[i]){
      case 'A':
      case 'a':
        strcat(morse,".- ");
        break;
      case 'B':
      case 'b':
        strcat(morse,"-... ");
        break;
      case 'C':
      case 'c':
        strcat(morse,"-.-. ");
        break;
      case 'D':
      case 'd':
        strcat(morse,"-.. ");
        break;
      case 'E':
      case 'e':
        strcat(morse,". ");
        break;
      case 'F':
      case 'f':
        strcat(morse,"..-. ");
        break;
      case 'G':
      case 'g':
        strcat(morse,"--. ");
        break;
      case 'H':
      case 'h':
        strcat(morse,".... ");
        break;
      case 'I':
      case 'i':
        strcat(morse,".. ");
        break;
      case 'J':
      case 'j':
        strcat(morse,".--- ");
        break;
      case 'K':
      case 'k':
        strcat(morse,"-.- ");
        break;
      case 'L':
      case 'l':
        strcat(morse,".-.. ");
        break;
      case 'M':
      case 'm':
        strcat(morse,"-- ");
        break;
      case 'N':
      case 'n':
        strcat(morse,"-. ");
        break;
      case 'O':
      case 'o':
        strcat(morse,"--- ");
        break;
      case 'P':
      case 'p':
        strcat(morse,".--. ");
        break;
      case 'Q':
      case 'q':
        strcat(morse,"--.- ");
        break;
      case 'R':
      case 'r':
        strcat(morse,".-. ");
        break;
      case 'S':
      case 's':
        strcat(morse,"... ");
        break;
      case 'T':
      case 't':
        strcat(morse,"- ");
        break;
      case 'U':
      case 'u':
        strcat(morse,"..- ");
        break;
      case 'V':
      case 'v':
        strcat(morse,"...- ");
        break;
      case 'W':
      case 'w':
        strcat(morse,".-- ");
        break;
      case 'X':
      case 'x':
        strcat(morse,"-..- ");
        break;
      case 'Y':
      case 'y':
        strcat(morse,"-.-- ");
        break;
      case 'Z':
      case 'z':
        strcat(morse,"--.. ");
        break;
      case ' ':
        strcat(morse,"/ ");
        break;
      case '\n':
        strcat(morse,"\n");
        break;
      default:
        printf("Invalid character.\n");
        return 0;
    }
  }
  printf("Morse code for your text:\n%s", morse);
  return 0;
}