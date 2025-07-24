//FormAI DATASET v1.0 Category: Data validation ; Style: surprised
#include <stdio.h>

int main() {
   int age;
   char name[20], address[100], email[30], email_check[30];

   printf("Welcome to the data validation program!\n");
   printf("Please enter your name:\n");
   scanf("%s", name);

   printf("Please enter your age:\n");
   scanf("%d", &age);

   if (age < 18) {
      printf("Sorry %s, you must be at least 18 years old to use this program.\n", name);
      return 0;
   }

   printf("Please enter your home address:\n");
   scanf("%s", address);

   printf("Please enter your email address:\n");
   scanf("%s", email);

   printf("Please re-enter your email address:\n");
   scanf("%s", email_check);

   if (strcmp(email, email_check) != 0) {
      printf("Email addresses do not match. Please try again.\n");
      return 0;
   }

   printf("Congratulations, %s! Your data has been successfully validated!\n", name);
   printf("Name: %s\n", name);
   printf("Age: %d\n", age);
   printf("Address: %s\n", address);
   printf("Email: %s\n", email);

   return 0;
}