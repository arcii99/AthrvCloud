//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include<stdio.h>
#include<string.h>

int main() {
   char sentence[1000], word[100], translation[1000], temp[1000];
   int i, j, k, n=0, flag=0;

   printf("Enter a sentence in C Cat Language: ");
   fgets(sentence, sizeof(sentence), stdin);

   for(i=0; sentence[i]!='\0'; i++) {
      if(sentence[i]==' ') {
         word[n]='\0';
         n=0;
         flag=0;
         for(j=0; word[j]!='\0'; j++) {
            if(word[j]=='c' && word[j+1]=='a' && word[j+2]=='t') {
               strcat(translation, "dog");
               flag=1;
            }
         }
         if(flag==0) {
            strcat(translation, word);
         }
         strcat(translation, " ");
      }
      else {
         word[n]=sentence[i];
         n++;
      }
   }
   word[n]='\0';
   flag=0;
   for(j=0; word[j]!='\0'; j++) {
      if(word[j]=='c' && word[j+1]=='a' && word[j+2]=='t') {
         strcat(translation, "dog");
         flag=1;
      }
   }
   if(flag==0) {
      strcat(translation, word);
   }

   printf("\nTranslated Sentence: ");
   printf("%s\n", translation);

   return 0;
}