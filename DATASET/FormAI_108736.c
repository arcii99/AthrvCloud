//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include<stdio.h>
#include<ctype.h>

int main(){
  char text[1000], ch;  //text array to store input, ch to temporarily hold each character of input
  int i, vowels=0, consonants=0, digits=0, spaces=0, punctuations=0;

  printf("Enter a piece of text: ");

  //accept input from user
  fgets(text, 1000, stdin);

  //calculate the frequency of vowels,consonants,digits,spaces and punctuations in the text
  for(i=0; text[i]!='\0'; ++i){
    ch = tolower(text[i]);  //convert to lowercase

    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
      ++vowels;
    }
    else if((ch>='a' && ch<='z')){
      ++consonants;
    }
    else if(ch>='0' && ch<='9'){
      ++digits;
    }
    else if(ch==' '){
      ++spaces;
    }
    else if(ch=='!' || ch=='?' || ch=='.' || ch==',' || ch==';' || ch==':'){
      ++punctuations;
    }
  }

  printf("\n\nStatistics of text entered:");
  printf("\nVowels: %d", vowels);
  printf("\nConsonants: %d", consonants);
  printf("\nDigits: %d", digits);
  printf("\nSpaces: %d", spaces);
  printf("\nPunctuations: %d", punctuations);

  return 0;
}