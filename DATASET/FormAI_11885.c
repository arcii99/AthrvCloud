//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: minimalist
#include<stdio.h>
#include<string.h>

int main()
{
   char c_code[1000];
   printf("Enter your C code:\n");
   fgets(c_code, 1000, stdin);

   char translated_code[1000];
   int i=0, j=0;
   
   while(c_code[i] != '\0')
   {
      if(c_code[i] == '/')
      {
         if(c_code[i+1] == '/')
         {
            // Single line comment
            while(c_code[i] != '\n' && c_code[i] != '\0')
            {
               i++;
            }
            continue;
         }
         else if(c_code[i+1] == '*')
         {
            // Multi-line comment
            i += 2;
            while(1)
            {
               if(c_code[i] == '*' && c_code[i+1] == '/')
               {
                  i += 2;
                  break;
               }
               i++;
            }
            continue;
         }
      }
      
      // Translate C syntax to C Cat syntax
      if(strncmp(&c_code[i], "if", 2) == 0)
      {
         strcat(translated_code, "if_i_can_has_cheezburger_jumps_ova");
         i += 2;
         j += strlen("if_i_can_has_cheezburger_jumps_ova");
      }
      else if(strncmp(&c_code[i], "else", 4) == 0)
      {
         strcat(translated_code, "els_uh_ohs_no_cheezburgers");
         i += 4;
         j += strlen("els_uh_ohs_no_cheezburgers");
      }
      else if(strncmp(&c_code[i], "while", 5) == 0)
      {
         strcat(translated_code, "wile_i_can_has_cheezburger_jumps_ova");
         i += 5;
         j += strlen("wile_i_can_has_cheezburger_jumps_ova");
      }
      else if(strncmp(&c_code[i], "for", 3) == 0)
      {
         strcat(translated_code, "fur_i_can_has_cheezburgers_0_2_counz");
         i += 3;
         j += strlen("fur_i_can_has_cheezburgers_0_2_counz");
      }
      else if(c_code[i] == '=')
      {
         strcat(translated_code, "gets");
         i++;
         j += strlen("gets");
      }
      else
      {
         translated_code[j] = c_code[i];
         i++;
         j++;
      }
   }
   
   printf("Your C Cat code is:\n%s", translated_code);
   
   return 0;
}