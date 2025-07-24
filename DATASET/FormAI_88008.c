//FormAI DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

// Function to count the number of vowels in the given text
int count_vowels(char* text){
   int count = 0;
   for(int i=0;i<strlen(text);i++){
      if(text[i]=='a' || text[i]=='e'|| text[i]=='i' || text[i]=='o' || text[i]=='u' ||
         text[i]=='A' || text[i]=='E'|| text[i]=='I' || text[i]=='O' || text[i]=='U'){
         count++;
      }
   }
   return count;
}

// Function to count the number of consonants in the given text
int count_consonants(char* text){
   int count = 0;
   for(int i=0;i<strlen(text);i++){
      if(isalpha(text[i]) && !isdigit(text[i])){
         if(text[i]!='a' && text[i]!='e'&& text[i]!='i' && text[i]!='o' && text[i]!='u' && 
            text[i]!='A' && text[i]!='E'&& text[i]!='I' && text[i]!='O' && text[i]!='U'){
            count++;
         }
      }
   }
   return count;
}

int main(){
   char text[100];
   printf("Enter the text: ");
   fgets(text, 100, stdin);
   
   printf("The input text is: %s\n", text);
   
   int num_vowels = count_vowels(text);
   int num_consonants = count_consonants(text);
   
   printf("The number of vowels in the text is: %d \n", num_vowels);
   printf("The number of consonants in the text is: %d \n", num_consonants);

   return 0;
}