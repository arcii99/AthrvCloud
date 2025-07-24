//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include<stdio.h>
#include<string.h>

int main(){
   char sentence[100];
   int vowels=0;
   int consonants=0;
   int digits=0;
   int spaces=0;
   int punctuations=0;

   printf("Enter a sentence:");
   fgets(sentence,sizeof(sentence),stdin);

   for(int i=0;i<strlen(sentence);i++){
      if(sentence[i]=='a' || sentence[i]=='e' || sentence[i]=='i' || sentence[i]=='o' || sentence[i]=='u' || sentence[i]=='A' || sentence[i]=='E' || sentence[i]=='I' || sentence[i]=='O' || sentence[i]=='U'){
         vowels++;
      }
      else if((sentence[i]>='a'&& sentence[i]<='z') || (sentence[i]>='A'&& sentence[i]<='Z')){
         consonants++;
      }
      else if(sentence[i]>='0' && sentence[i]<='9'){
         digits++;
      }
      else if(sentence[i]==' '){
         spaces++;
      }
      else{
         punctuations++;
      }
   }

   printf("\nVowels: %d",vowels);
   printf("\nConsonants: %d",consonants);
   printf("\nDigits: %d",digits);
   printf("\nSpaces: %d",spaces);
   printf("\nPunctuations: %d",punctuations);

   return 0;
}