//FormAI DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char sender[30], recipient[30], subject[50];

   printf("*** WELCOME TO HAPPY EMAIL CLIENT! ***\n\n");

   // Get user input for sender, recipient, and subject
   printf("Enter your name as the sender: ");
   scanf("%s", sender);
   printf("Enter recipient name: ");
   scanf("%s", recipient);
   printf("Enter subject of email: ");
   scanf("%s", subject);

   printf("\n");

   // Connect to server
   printf("Connecting to server...\n");
   printf("Connected!\n\n");

   // Body of email
   printf("Dear %s,\n", recipient);
   printf("I hope this email finds you well! :)\n\n");
   printf("I just wanted to reach out and say hello. Life has been treating me well, and I'm hoping it's the same for you. :D\n\n");
   printf("Sending happy vibes your way! :D\n\n");
   printf("Best regards,\n");
   printf("%s\n", sender);

   // Send email
   printf("Sending email...\n");
   printf("Email sent successfully!\n");

   return 0;
}