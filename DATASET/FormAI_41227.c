//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char input[100];
   char output[100];
   printf("Enter your daring text: ");
   fgets(input, sizeof(input), stdin);
    
   for(int i=0;i<strlen(input);i++){
       if(i%2 == 0){
           output[i] = input[i] + 3;    
       } else {
           output[i] = input[i] - 3; 
       }
   }
   printf("Brave output: %s", output);
   return 0;
}