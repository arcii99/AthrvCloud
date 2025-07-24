//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {

   char hex[17], message[100];
   int i, num;

   printf("Hello my dear, I have a special program just for you\n");
   printf("Enter hexadecimal number: ");
   scanf("%s", hex);

   for(i=0; hex[i]!='\0'; i++){
   
      if(hex[i]>='0' && hex[i]<='9')
         num = hex[i] - 48;
         
      else if(hex[i]>='a' && hex[i]<='f')
         num = hex[i] - 87;
         
      else if(hex[i]>='A' && hex[i]<='F')
         num = hex[i] - 55;
         
      else {
         printf("Invalid hexadecimal digit. Please try again!");
         exit(0);
      }
   }

   printf("\nThe decimal value of %s is %d \n", hex, num);

   printf("\nNow that I have shown you the power of my program, let's have a romantic dinner tonight!\n");

   printf("\nWould you like to send me a message? ");
   fgets(message, sizeof(message), stdin);

   printf("\nI will convert your message into hexadecimal -\n");

   for(i=0; message[i]!='\0'; i++) {
   
      printf("%x", message[i]);
   }

   printf("\nI love spending time with you my dear! Let's do this again soon!\n");

   return 0;
}