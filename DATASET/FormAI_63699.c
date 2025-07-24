//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   printf("Enter a sentence: ");
   fgets(input, 100, stdin);
   printf("You entered: %s", input);
   
   int vowels = 0, consonants = 0, digits = 0, spaces = 0, others = 0;
   int length = strlen(input);
   
   for(int i = 0; i < length; i++){
       
       if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||
          input[i] == 'o' || input[i] == 'u' || input[i] == 'A' ||
          input[i] == 'E' || input[i] == 'I' || input[i] == 'O' ||
          input[i] == 'U')
       {
          vowels++;
       }
       
       else if((input[i] >= 'a' && input[i] <= 'z') || 
               (input[i] >= 'A' && input[i] <= 'Z'))
       {
           consonants++;
       }
       
       else if(input[i] >= '0' && input[i] <= '9')
       {
           digits++;
       }
       
       else if(input[i] == ' ')
       {
           spaces++;
       }
       
       else
       {
           others++;
       }
   }
   
   printf("\nNumber of vowels in the sentence is: %d", vowels);
   printf("\nNumber of consonants in the sentence is: %d", consonants);
   printf("\nNumber of digits in the sentence is: %d", digits);
   printf("\nNumber of spaces in the sentence is: %d", spaces);
   printf("\nNumber of other characters in the sentence is: %d", others);
   
   return 0;
}