//FormAI DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <ctype.h>

int main() {
   char text[1000], c;
   int words=1, characters=0, vowels=0, consonants=0, digits=0, spaces=0;

   printf("Enter your sentence: ");
   fgets(text, sizeof(text), stdin); //accepts input from the user
   
   for (int i=0; text[i]!='\0'; i++) { //loops through each character in the input
       c = tolower(text[i]); //converts the character to lowercase

       if (isalpha(c)) { //checks if the character is a letter
           characters++;
           if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { //checks if it is a vowel
               vowels++;
           }
           else { //if it is not a vowel, it is a consonant
               consonants++;
           }
       }
       else if (isdigit(c)) { //checks if the character is a digit
           digits++;
       }
       else if (isspace(c)) { //checks if the character is a space
           spaces++;
           words++;
       }
   }

   printf("\nWord count: %d\n", words);
   printf("Character count: %d\n", characters);
   printf("Vowel count: %d\n", vowels);
   printf("Consonant count: %d\n", consonants);
   printf("Digit count: %d\n", digits);
   printf("Space count: %d\n", spaces);

   return 0;
}