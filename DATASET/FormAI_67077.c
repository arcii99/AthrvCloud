//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include<stdio.h>

int main(){
   
   printf("Welcome to my Digital Diary!\n");
   printf("Today's date is 01/04/2022. Wait, that's not right...\n");
   printf("Ah, April Fool's! Let me adjust that date real quick.\n");
   printf("There we go, today's date is actually 04/01/2022. Phew.\n");
   
   char entry[300];
   printf("Please enter your diary entry for today:\n");
   fgets(entry, 300, stdin);
   
   printf("\n\n\nEntry saved! Here's what you wrote:\n");
   printf("%s",entry);
   
   printf("\n\n\nOh no, my diary has been hacked by a hacker named 'Sneaky Steve'!\n");
   printf("Quick, we need to change the password to something he won't guess...\n");
   printf("I know! Let's make the password '1234'! Genius, right?\n");
   
   int password;
   printf("\n\n\nPlease enter your new password (it's definitely not '1234'):\n");
   scanf("%d",&password);
   
   printf("\n\n\nPassword changed successfully! Let's test it out by logging back in...\n");
   printf("Please enter your password:\n");
   scanf("%d",&password);
   
   if(password == 1234){
      printf("\n\n\nOops, I guess we forgot to actually change the password. Good thing this is just a joke program...\n");
   }
   else{
      printf("\n\n\nInvalid password! You shall not pass!\n");
   }
   
   return 0;
}