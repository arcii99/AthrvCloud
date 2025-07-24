//FormAI DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <string.h>

struct Contact {
   char name[50];
   char phone[20];
   char email[50];
};

int main() {
   struct Contact c1, c2;
   
   printf("Enter Lover 1's Name: ");
   scanf("%s",c1.name);
   printf("Enter Lover 1's Phone Number: ");
   scanf("%s",c1.phone);
   printf("Enter Lover 1's Email Address: ");
   scanf("%s",c1.email);
   
   printf("\nEnter Lover 2's Name: ");
   scanf("%s",c2.name);
   printf("Enter Lover 2's Phone Number: ");
   scanf("%s",c2.phone);
   printf("Enter Lover 2's Email Address: ");
   scanf("%s",c2.email);
   
   printf("\n\n------------------------------\n");
   printf("Lovebirds' Phone Book\n");
   printf("------------------------------\n");
   
   printf("%s\t\t%s\t%s\n",c1.name,c1.phone,c1.email);
   printf("%s\t\t%s\t%s\n",c2.name,c2.phone,c2.email);
   
   printf("\nHey Lovebirds, keep each other's hearts close and these contact details closer!\n");
   
   return 0;
}