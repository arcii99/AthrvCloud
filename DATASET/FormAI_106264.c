//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int wordCount(char* str, int* freq) {
   int count = 0;

   while (*str) {
       if (*str == ' ') {
           count++;
       }
       else {
           *(freq + tolower(*str) - 97) += 1;
       }
       str++;
   }

   return count+1;
}

int main() {
    char str[100];
    int freq[26] = {0};

    printf("Enter a sentence: ");
    fgets(str, 100, stdin);

    int numWords = wordCount(str, freq);

    printf("\nThe frequency of each letter in the sentence is: \n");

    for(int i = 0; i < 26; i++) {
        printf("%c: %d\n", i+97, freq[i]);
    }

    printf("\nThe total number of words in the sentence is: %d", numWords);

    return 0; 
}