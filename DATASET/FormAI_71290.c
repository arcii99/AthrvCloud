//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include<stdio.h>
#include<string.h>

int main(){
   int flag = 0;
   char my_string[50];
   printf("Welcome to the Palindrome Checker!\n");
   printf("Enter the string you want to check for Palindrome: ");
   scanf("%s", my_string);
   int length = strlen(my_string)-1;
   for(int i=0;i<=length;i++){
        if(my_string[i] != my_string[length-i]){
            flag = 1;
            break;
        }
   }

   if(flag == 0){
        printf("\nCongratulations! The entered string is a Palindrome\n");
   }
   else{
        printf("\nSorry the entered string is not a Palindrome\n");
   }
   return 0;
}