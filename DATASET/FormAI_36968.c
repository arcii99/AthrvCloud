//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
   char cat_code[] = "'.' = 'meow'\n',' = 'purr'\n';' = 'hiss'\n'(' = 'scratch('\n')' = ')scratch'\n'{' = 'claw{'\n'}' = '}claw'\n'[' = 'swat['\n']' = ']swat'\n'<' = 'sniff<'\n'>' = '>sniff'\n'+' = 'pounce+'\n'-' = 'stalk-'\n'*' = 'bat*'\n'/' = 'lick/'\n'%' = '%lick'\n'=' = '=mark'\n'!' = '!hiss'\n'&' = '&murr&'\n'|' = '|purr|'\n'^' = '^scratch^'\n'~' = '~lick~'\n'&&' = '&&murr&&'\n'||' = '||purr||'\n'==' = '==mark=='\n'!=' = '!=hiss!='\n'>=' = '>=sniff='\n'<=' = '<=sniff='\n'<<' = '<<stretch'\n'>>' = '>>curl'\n";
   
   char c_code[1000];
   
   printf("Enter the C code:\n");
   scanf("%[^\n]", c_code);
   
   for (int i=0; i<strlen(c_code); i++) {
      if (c_code[i] == '\n') {
         printf("%c", c_code[i]);
      }
      else {
         char cat_code_translation[100];
         int j=0;
         while (cat_code[j] != '\n') {
            if (cat_code[j] == c_code[i]) {
               int k=0;
               while (cat_code[j+k] != '\n') {
                  cat_code_translation[k] = cat_code[j+k];
                  k++;
               }
               cat_code_translation[k] = '\0';
            }
            j++;
         }
         printf("%s", cat_code_translation);
      }
   }
   
   return 0;
}