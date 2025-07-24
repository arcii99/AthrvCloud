//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include<stdio.h>

int main(){

   char alien_language[] = {'å', 'ß', '©', '∂', 'ƒ', '©', '˙', 'ß', 'å', '≤', 'µ', 'Ω', 'ø'};
   char english_language[100];

   printf("\nWelcome to the Alien Language Translator\n");
   printf("\nEnter the sentence in the Alien Language: ");

   for(int i=0;i<100;i++) {
      scanf("%c", &english_language[i]);
      if(english_language[i] == '\n') {
         english_language[i] = '\0';
         break;      
      }
   }

   printf("\nTranslating your sentence...\n");
   printf("\nYou said: ");
   for(int i=0;i<100;i++) {
      if(english_language[i] == '\0') {
         break;
      }
      printf("%c", english_language[i]);
   }

   printf("\nTranslation: ");
   for(int i=0;i<100;i++) {
      if(english_language[i] == '\0') {
         break;
      }
      for(int j=0;j<13;j++) {
         if(english_language[i] == alien_language[j]) {
            printf("%c", 97+j);
            break;
         }
      }
   }

   printf("\nThank you for using the Alien Language Translator!\n");
   return 0;
}