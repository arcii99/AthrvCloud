//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include<stdio.h>

int main(){

//initialize variables
char str[100];
int words=1,character=0,i;

//ask user for input
printf("Enter a sentence to count words and characters:");
fgets(str,100,stdin);

//loop through the input string
for(i=0;str[i]!='\0';i++){
   
   //increment character counter
   character++;

   //if character is a space, increment word counter
   if(str[i]==' '){
      words++;
   }
}

//print results
printf("\nThere are %d words in the sentence.",words);
printf("\nThere are %d characters in the sentence.",character);

return 0;

}