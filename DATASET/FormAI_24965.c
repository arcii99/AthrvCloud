//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main(void) {

   char email_address[MAX_BUFFER_SIZE], subject[MAX_BUFFER_SIZE], message[MAX_BUFFER_SIZE];
   
   printf("Welcome to our C Email Client!\n\n");
   printf("Please enter the recipient's email address:\n");
   scanf("%s", email_address);
   
   printf("Please enter the email subject:\n");
   scanf("%s", subject);
   
   printf("Please enter your message:\n");
   scanf("%s", message);
   
   // TODO: Send the email using the SMTP protocol
   
   printf("Your email has been sent successfully!\n");
   
   return EXIT_SUCCESS;
}