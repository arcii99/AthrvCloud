//FormAI DATASET v1.0 Category: Text processing ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void main(){
  char text[1000], cipher[1000];
  int i;

  printf("Enter the input text to encode:\n");
  scanf("%[^\n]s", text);

  //Encoding the input text
  for(i=0; text[i] != '\0'; i++){
    if(isalpha(text[i])){
      if(text[i] >= 'a' && text[i] <= 'z'){
        cipher[i] = (char)(219 - (int)text[i]);
      }
      else{
        cipher[i] = (char)(155 - (int)text[i]);
      } 
    }
    else{
      cipher[i] = text[i];
    }
  }

  printf("The encoded text is : %s\n", cipher);
  
  //Decoding the encoded text
  for(i=0; cipher[i] != '\0'; i++){
    if(isalpha(cipher[i])){
      if(cipher[i] >= 'a' && cipher[i] <= 'z'){
        text[i] = (char)(219 - (int)cipher[i]);
      }
      else{
        text[i] = (char)(155 - (int)cipher[i]);
      } 
    }
    else{
      text[i] = cipher[i];
    }
  }

  printf("The decoded text is : %s\n", text);

}