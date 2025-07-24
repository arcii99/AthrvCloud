//FormAI DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Welcome to Chuck's Email Client!\n");
   printf("Please enter your email address: ");

   char email[50];
   scanf("%s", email);

   printf("You have %d unread messages. Would you like to read them? (Y/N)\n", rand() % 100);
   char choice;
   scanf(" %c", &choice);

   if (choice == 'Y' || choice == 'y')
   {
      printf("Sorry, this feature is not yet implemented. But here's a joke instead:\n");

      printf("Why did the email client blush?\n");
      printf("Because it saw the attachment's size!\n");
   }
   else if (choice == 'N' || choice == 'n')
   {
      printf("Are you sure? You might be missing out on some juicy gossip!\n");
      printf("Just kidding, there are no juicy gossip. But there's a funny quote here:\n");

      printf("I never apologize. I'm sorry, but that's just the way I am.\n");
   }
   else
   {
      printf("Invalid choice, but I won't judge. Here's another joke instead:\n");

      printf("Why do programmers prefer dark mode?\n");
      printf("Because light attracts bugs!\n");
   }

   printf("Thanks for using Chuck's Email Client!\n");
   return 0;
}