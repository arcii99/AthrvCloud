//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

int main(){
  char phrase[100];
  printf("Please enter your phrase in the Alien Language: ");
  scanf("%s", phrase);
  int phraseLength = strlen(phrase);

  printf("Translation: ");
  for(int i=0; i<phraseLength; i++){
    switch(phrase[i]){
      case 'a':
        printf("∫");
        break;
      case 'b':
        printf("ç");
        break;
      case 'c':
        printf("∂");
        break;
      case 'd':
        printf("´");
        break;
      case 'e':
        printf("´");
        break;
      case 'f':
        printf("ƒ");
        break;
      case 'g':
        printf("©");
        break;
      case 'h':
        printf("˙");
        break;
      case 'i':
        printf("ˆ");
        break;
      case 'j':
        printf("∆");
        break;
      case 'k':
        printf("˚");
        break;
      case 'l':
        printf("¬");
        break;
      case 'm':
        printf("µ");
        break;
      case 'n':
        printf("˜");
        break;
      case 'o':
        printf("ø");
        break;
      case 'p':
        printf("π");
        break;
      case 'q':
        printf("œ");
        break;
      case 'r':
        printf("®");
        break;
      case 's':
        printf("ß");
        break;
      case 't':
        printf("†");
        break;
      case 'u':
        printf("¨");
        break;
      case 'v':
        printf("√");
        break;
      case 'w':
        printf("∑");
        break;
      case 'x':
        printf("≈");
        break;
      case 'y':
        printf("¥");
        break;
      case 'z':
        printf("Ω");
        break;
      default:
        printf("%c", phrase[i]);
        break;
    }
  }
  return 0;
}