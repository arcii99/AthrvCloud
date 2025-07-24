//FormAI DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>   //header file for input and output operations in C
#include <string.h>  //header file for string operations in C

int main() {
   char str[100], c;    //character array declaration
   int i, j=0, freq[26]={0};   //integer variable declaration
   
   printf("Enter a string: ");   //asking user to input a string
   fgets(str, sizeof(str), stdin);   //reading the input string
   
   printf("Enter a character to find the frequency: "); //asking user to input a character
   scanf("%c",&c);       //reading the input character
   
   while (str[j] != '\0')   //looping through the input string for each character to find its frequency
   {
      if (str[j] >= 'a' && str[j] <= 'z')   //checking if character at i is a lowercase alphabet
         freq[str[j]-'a']++;   //increasing the count of particular character in its respective index position
      else if (str[j] >= 'A' && str[j] <= 'Z')   //checking if character at i is a uppercase alphabet
         freq[str[j]-'A']++;   //increasing the count of particular character in its respective index position
      j++;
   }
   printf("Frequency of %c = %d\n", c, freq[c - 'a']);   //printing the frequency of the input character
    
   return 0;
}