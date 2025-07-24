//FormAI DATASET v1.0 Category: Encryption ; Style: systematic
// Example program for Caesar Cipher Encryption in C
#include<stdio.h>
#include<string.h>

int main()
{
   char plaintext[50],ciphertext[50];
   int i,key;

   printf("Enter a plaintext message:\n");
   fgets(plaintext,50,stdin);

   printf("Enter an encryption key (1-25):\n");
   scanf("%d",&key);

   for(i=0;i<strlen(plaintext);i++)
   {
      if(plaintext[i]==' ')
      {
         ciphertext[i]=' ';
      }
      else if(plaintext[i]>='A' && plaintext[i]<='Z')
      {
         ciphertext[i]=((plaintext[i]-'A'+key)%26)+'A';
      }
      else if(plaintext[i]>='a' && plaintext[i]<='z')
      {
         ciphertext[i]=((plaintext[i]-'a'+key)%26)+'a';
      }
      else
      {
         ciphertext[i]=plaintext[i];
      }
   }
   ciphertext[i]='\0';

   printf("The ciphertext is:\n%s",ciphertext);

   return 0;
}