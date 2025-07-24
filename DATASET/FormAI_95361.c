//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>

int main() {
   char text[1000];
   int vowels = 0, digits = 0, consonants = 0, i;

   printf("Enter text: ");
   fgets(text, 1000, stdin);

   for(i = 0; text[i] != '\0'; ++i) {
       if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U') {
           ++vowels;
       }
       else if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z')) {
           ++consonants;
       }
       else if(text[i]>='0' && text[i]<='9') {
           ++digits;
       }
   }

   printf("Number of vowels in the text: %d\n", vowels);
   printf("Number of consonants in the text: %d\n", consonants);
   printf("Number of digits in the text: %d\n", digits);

   return 0;
}