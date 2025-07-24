//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: expert-level
#include<stdio.h>
#include<string.h>

// User-defined function to detect intrusion 
void detect_intrusion(char *str)
{
   // List of keywords to be detected
   char *keywords[] = {"hack", "password", "admin", "root", "virus", "malware"};

   int i, j, len, flag;
   
   len = strlen(str);

   // Loop through string searching for keywords
   for(i = 0; i < len; i++)
   {
      flag = 0;
      for(j = 0; j < 6; j++)
      {
         if(str[i] == keywords[j][0])
         {
            int k = i;
            while(str[k] == keywords[j][k-i] && k < len && k-i < strlen(keywords[j]))
            {
               k++;
            }
            
            if(k-i == strlen(keywords[j]))
            {
               printf("Intrusion detected: %s\n", keywords[j]);
               flag = 1;
               break;
            }
         }
      }
      
      if(flag == 1)
      {
         break;
      }
   }
}

int main()
{
   char input[100];
   
   printf("Enter a string: ");
   fgets(input, 100, stdin);
   
   detect_intrusion(input);
   
   return 0;
}