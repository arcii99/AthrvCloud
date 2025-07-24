//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include<stdio.h>
#include<string.h>

int main()
{
   char str[100];
   int vowels=0, consonants=0, digits=0, spaces=0;

   printf("Enter a string of characters: ");
   fgets(str, sizeof(str), stdin);   //taking input from user using fgets function

   for(int i=0; i<strlen(str); i++)  //iterating over each character of the string
   {
      if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')  //checking if the character is a vowel
         vowels++;
      else if((str[i]>='a'&& str[i]<='z') || (str[i]>='A'&& str[i]<='Z'))  //checking if the character is a consonant
         consonants++;
      else if(str[i]>='0'&& str[i]<='9')  //checking if the character is a digit
         digits++;
      else if (str[i] == ' ')  //checking if the character is a space
         spaces++;
   }

   printf("\nNumber of vowels in the string: %d", vowels); 
   printf("\nNumber of consonants in the string: %d", consonants);
   printf("\nNumber of digits in the string: %d", digits);
   printf("\nNumber of spaces in the string: %d", spaces);

   return 0;  //returning 0 to exit the program correctly
}