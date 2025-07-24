//FormAI DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define email structure
struct email {
   char sender[50], receiver[50], subject[100], message[500];
};

// Function for displaying menu options
void menu() {
   printf("\nEmail Client\n");
   printf("1. Compose email\n");
   printf("2. View inbox\n");
   printf("3. Exit\n");
}

// Function for composing and sending email
void compose_email() {
   struct email e;
   FILE *fp;

   // Get inputs
   printf("\nEnter sender email:\n");
   scanf("%s", e.sender);
   printf("Enter receiver email:\n");
   scanf("%s", e.receiver);
   printf("Enter subject:\n");
   scanf("%s", e.subject);
   printf("Enter message:\n");
   fflush(stdin);
   fgets(e.message, 500, stdin);

   // Save email to file
   fp = fopen("inbox.txt", "a");
   fprintf(fp, "%s;%s;%s;%s\n", e.sender, e.receiver, e.subject, e.message);
   fclose(fp);

   printf("\nEmail sent successfully!\n");
}

// Function for viewing inbox
void view_inbox() {
   FILE *fp;
   char buffer[500];
   char *sender, *receiver, *subject, *message;

   // Open inbox file
   fp = fopen("inbox.txt", "r");

   // Read emails from file and display
   printf("\nInbox:\n");
   while(fgets(buffer, 500, fp)) {
      sender = strtok(buffer, ";");
      receiver = strtok(NULL, ";");
      subject = strtok(NULL, ";");
      message = strtok(NULL, ";");

      printf("\nSender: %s\tReceiver: %s\tSubject: %s\nMessage: %s", sender, receiver, subject, message);
   }

   fclose(fp);
}

int main() {
   int choice;

   do {
      menu();

      // Get user choice
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      // Call appropriate function based on choice
      switch(choice) {
         case 1:
            compose_email();
            break;
         case 2:
            view_inbox();
            break;
         case 3:
            printf("\nExiting program...\n");
            exit(0);
         default:
            printf("\nInvalid choice. Try again.\n");
      }

   } while(1);

   return 0;
}