//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

char *generate_password();

int main()
{
   char *password = generate_password();
   printf("Generated Password: %s\n", password);
   free(password);

   return 0;
}

char *generate_password()
{
   char *password = malloc(PASSWORD_LENGTH + 1);
   int i, random_number;

   srand(time(0));

   for (i = 0; i < PASSWORD_LENGTH; i++)
   {
      random_number = rand() % 77;

      if (random_number < 10)
         password[i] = '0' + random_number;
      else if (random_number < 36)
         password[i] = 'a' - 10 + random_number;
      else if (random_number < 62)
         password[i] = 'A' - 36 + random_number;
      else
      {
         switch (random_number)
         {
         case 62:
            password[i] = '_';
            break;
         case 63:
            password[i] = '-';
            break;
         case 64:
            password[i] = '+';
            break;
         case 65:
            password[i] = '*';
            break;
         case 66:
            password[i] = '%';
            break;
         case 67:
            password[i] = '(';
            break;
         case 68:
            password[i] = ')';
            break;
         case 69:
            password[i] = '[';
            break;
         case 70:
            password[i] = ']';
            break;
         case 71:
            password[i] = '{';
            break;
         case 72:
            password[i] = '}';
            break;
         case 73:
            password[i] = '<';
            break;
         case 74:
            password[i] = '>';
            break;
         case 75:
            password[i] = '=';
            break;
         case 76:
            password[i] = '?';
            break;
         }
      }
   }

   password[PASSWORD_LENGTH] = '\0';

   return password;
}