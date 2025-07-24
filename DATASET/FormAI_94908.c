//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
   char text[100];
   char morse[37][10]={".-","-...","-.-.","-..",".","..-.","--.",
                        "....","..",".---","-.-",".-..","--","-.",
                        "---",".--.","--.-",".-.","...","-","..-",
                        "...-",".--","-..-","-.--","--..","-----",
                        ".----","..---","...--","....-",".....",
                        "-....","--...","---..","----."};

   printf("Enter text to convert to Morse code:\n");
   gets(text);
   
   int length = strlen(text);
   
   for(int i=0; i<length; i++) {
      if(text[i]==' ') {
         printf(" ");
      } else {
         int ascii = text[i];
         if(ascii>=65 && ascii<=90) { // capital letter
            printf("%s ", morse[ascii-65]);
         } else if(ascii>=97 && ascii<=122) { // small letter
            printf("%s ", morse[ascii-97]);
         } else if(ascii>=48 && ascii<=57) { // numbers
            printf("%s ", morse[ascii+4]);
         }
      }
   }
   return 0;
}