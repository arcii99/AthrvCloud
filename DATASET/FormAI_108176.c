//FormAI DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {
   char str1[20], str2[20], str3[20]; //Declaring three character arrays of size 20
   int len, result, i; //Declaring integer variables

   //Input from user
   printf("Enter the first string: ");
   scanf("%s",str1);
   printf("Enter the second string: ");
   scanf("%s",str2);

   //String length calculation
   len = strlen(str1);

   //Copying string1 into string3
   strcpy(str3, str1);

   //Concatenation of string1 and string2
   strcat(str1, str2);

   //Comparison of string1 and string2
   result = strcmp(str1, str2);

   //Printing output
   printf("\nLength of string1 = %d\n", len);
   printf("Concatenated string = %s\n", str1);
   printf("String comparison result = %d\n", result);

   //Reversing the string3
   for(i=0;i<len;i++){
      str3[i]=str1[len-i-1];
   }

   //Printing reversed string
   printf("Reversed string = %s", str3);

   return 0;
}