//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define email struct
typedef struct {
   char recipient[50];
   char sender[50];
   char subject[50];
   char message[500];
} Email;

// Define function to send email
void send_email(Email* email) {
   printf("Recipient: %s\n", email->recipient);
   printf("Sender: %s\n", email->sender);
   printf("Subject: %s\n", email->subject);
   printf("Message: %s\n", email->message);
   printf("Email sent successfully!\n");
}

// Main function
int main() {
   // Create new email
   Email my_email;
   strcpy(my_email.recipient, "john@example.com");
   strcpy(my_email.sender, "mary@example.com");
   strcpy(my_email.subject, "Hello John");
   strcpy(my_email.message, "Just wanted to say hi!");

   // Print email details
   printf("Email Details:\n");
   printf("Recipient: %s\n", my_email.recipient);
   printf("Sender: %s\n", my_email.sender);
   printf("Subject: %s\n", my_email.subject);
   printf("Message: %s\n", my_email.message);
   
   // Send email
   send_email(&my_email);

   return 0;
}