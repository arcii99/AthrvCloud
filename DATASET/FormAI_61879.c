//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
   char str[100];
   int num = 0;
   printf("Enter a string: ");
   scanf("%[^\n]%*c", str);

   for(int i = 0; str[i] != '\0'; i++) {
       if(str[i] >= '0' && str[i] <= '9') { 
            num += str[i] - '0';
            // converts char to int by subtracting ASCII value of 0
       }
       
   }
   printf("Sum of all digits in the string: %d\n", num);

   char upper[100];
   int length = strlen(str);
   for(int i = 0; i < length; i++) {
       if(str[i] >= 'a' && str[i] <= 'z') {
           upper[i] = str[i] - 32;
           // converts lowercase alphabet to corresponding uppercase by subtracting 32
       }
       else {
           upper[i] = str[i];
           // if not lowercase alphabet, keep the original character
       }
   }
   
   upper[length] = '\0'; // add null character to end of string
   printf("Uppercase version of the string: %s", upper);

   return 0;
}