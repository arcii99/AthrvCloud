//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include<stdio.h>
#include<string.h>

// This is a fun Password strength checker, prepare to be entertained

int main(){
    char password[50];
    int strength = 0;

    printf("Hello, I am the Password Strength Checker Bot!\n");
    printf("Please enter your password to see how strong it is: ");
    fgets(password, 50, stdin);

    if(strlen(password) < 8){
        printf("Your password is too short, try again with a longer password!\n");
        return 0;
    }

   char* ptr = password;

   while(*ptr){
       if(*ptr >= 'a' && *ptr <= 'z'){
           strength += 2;
       }
       else if(*ptr >= 'A' && *ptr <= 'Z'){
           strength += 4;
       }
       else if(*ptr >= '0' && *ptr <= '9'){
           strength += 3;
       }
       else{
           strength += 7;
       }
       ptr++;
   }

   if(strength < 10){
       printf("Your password is so weak, even a toddler could guess it!\n");
   }
   else if(strength >= 10 && strength < 20){
       printf("Your password is weak, try adding more uppercase letters!\n");
   }
   else if(strength >= 20 && strength < 30){
       printf("Your password is almost there, try adding more numbers!\n");
   }
   else if(strength >= 30 && strength < 40){
       printf("Your password is strong, but try adding some symbols for extra security!\n");
   }
   else{
       printf("Your password is unbreakable, did you hire a hacker to create it?! Amazing!\n");
   }

   return 0;
}