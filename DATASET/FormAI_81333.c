//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   int length, i, random_int;
   char password[20];
   time_t t;

   srand((unsigned) time(&t));

   printf("Enter the length of password: ");
   scanf("%d", &length);

   if(length < 8){
       printf("Error! Password length must be at least 8 characters long.\n");
       exit(0);
   }

   printf("Generating password...\n");

   for(i=0; i<length; i++) {
       random_int = rand() % 62;

       if(random_int < 10)
           password[i] = random_int + 48;
       else if(random_int < 36)
           password[i] = random_int + 55;
       else
           password[i] = random_int + 61;

       printf("%c", password[i]);
   }

   printf("\nCongratulations! Your password is secure!\n");

   return 0;
}