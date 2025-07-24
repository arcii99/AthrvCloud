//FormAI DATASET v1.0 Category: Email Client ; Style: invasive
#include<stdio.h>

int main() {
   char to[50], from[50], message[500], subject[100];
   printf("Enter recipient's email address : ");
   scanf("%s", to);
   printf("\nEnter sender's email address : ");
   scanf("%s", from);
   printf("\nEnter the subject of the email : ");
   scanf("%s", subject);
   printf("\nEnter the message you want to send : ");
   scanf("%s", message);
   printf("\nSending email to %s from %s\n\n", to, from);
   printf("Subject: %s\n\n", subject);
   printf("Message:\n%s\n", message);
   printf("\nEmail sent successfully!");
   return 0;
}