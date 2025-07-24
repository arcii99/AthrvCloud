//FormAI DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdio.h>
#include <string.h>
#define MAX_SPAM_WORDS 5

void convertToLowercase(char *string);
int checkForSpam(char *string);

int main()
{
   char message[1000];
   printf("Enter your message: ");
   fgets(message, 1000, stdin);

   // Convert message to lower case
   convertToLowercase(message);

   // Check for spam words
   int result = checkForSpam(message);

   if(result == 0)
   {
       printf("Your message is clean.\n");
   }
   else
   {
       printf("Your message contains spam words. Please review your message and try again.\n");
   }

   return 0;
}

/*
* Function to convert string to lowercase
*/
void convertToLowercase(char *string)
{
    int i;
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]>='A' && string[i]<='Z')
        {
            string[i]=string[i]+32;
        }
    }
}

/*
* Function to check if message contains spam words
*/
int checkForSpam(char *string)
{
    char *spamWords[MAX_SPAM_WORDS] = {"cash prize", "free", "lottery", "sex", "make money"};
    int i,j,k,found;

    for(i=0;i<MAX_SPAM_WORDS;i++)
    {
        found = 0;
        k=0;

        for(j=0;j<strlen(string);j++)
        {
            if(spamWords[i][k] == string[j])
            {
               found = 1;
               k++;
               if(k == strlen(spamWords[i]))
               {
                   return 1;
               }
            }
            else
            {
                found = 0;
                k = 0;
            }
        }
    }

    return 0;
}