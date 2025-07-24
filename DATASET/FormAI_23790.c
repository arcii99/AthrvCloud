//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include<stdio.h>
#include<string.h>

//Function to translate the alien language to English
void translate(char* alien_language, int len) 

{
   //Initializing the dictionary
   char dictionary[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 
                         'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
   int i, j;
   
   //Loop through each character in the alien language
   for(i=0; i<len; i++)
   {
      //Check if the character is a space or a period
      if(alien_language[i] == ' ' || alien_language[i] == '.')
      {
         printf("%c", alien_language[i]);
      }
      
      //Translate the character using the dictionary
      else
      {
         char alien_char = alien_language[i];
         int index = alien_char - 'a';
         printf("%c", dictionary[index]);
      }
   }
}

int main() 
{
   char alien_language[100];
   
   //Get the alien language input from the user
   printf("Enter the alien language: ");
   fgets(alien_language, 100, stdin);
   
   int len = strlen(alien_language);
   translate(alien_language, len);
   
   return 0;
}