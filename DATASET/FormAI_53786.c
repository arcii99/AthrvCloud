//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// function to convert a string to lowercase
void toLower(char str[]) {
   int i = 0;
   while (str[i]) {
      str[i] = tolower(str[i]);
      i++;
   }
}

// function to translate alien language "C"
void translate(char str[]) {
   char lang[26][3] = { // defining our own alien language C
                     "aa", // a
                     "ba", // b
                     "ca", // c
                     "da", // d
                     "ea", // e
                     "fa", // f
                     "ga", // g
                     "ha", // h
                     "ia", // i
                     "ja", // j
                     "ka", // k
                     "la", // l
                     "ma", // m
                     "na", // n
                     "oa", // o
                     "pa", // p
                     "qa", // q
                     "ra", // r
                     "sa", // s
                     "ta", // t
                     "ua", // u
                     "va", // v
                     "wa", // w
                     "xa", // x
                     "ya", // y
                     "za" // z
                  };
   int len = strlen(str);
   for(int i=0; i<len; i+=2) { // looping through pairs of characters
      for(int j=0; j<26; j++) { // nested loop through our C language
         if(strcmp(lang[j], &str[i]) == 0) { // if there's a match
            printf("%c", j+97); // print the corresponding letter from English alphabet
         }
      }
   }
}

int main() {
   char message[100];
   printf("Enter message in alien language C:\n");
   fgets(message, 100, stdin); // get input from user
   toLower(message); // convert input to lowercase
   printf("Translating...\n");
   translate(message); // call function to translate alien language C
   printf("\n");
   return 0;
}