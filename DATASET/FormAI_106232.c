//FormAI DATASET v1.0 Category: modern Encryption ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   char phrase[100];  
   int key;         
   int length;          

   printf("Enter a phrase to encrypt: ");
   fgets(phrase,100,stdin);

   length=strlen(phrase)-1;  

   printf("Enter an encryption key (1-25): ");
   scanf("%d", &key);
   printf("\n");

   for(int i=0;i<length;i++)
   {
       if(phrase[i]>='a' && phrase[i]<='z')  
          phrase[i]=((phrase[i]-97+key)%26)+97;  
       else if(phrase[i]>='A' && phrase[i]<='Z') 
          phrase[i]=((phrase[i]-65+key)%26)+65; 
   }

   printf("Your encrypted phrase is: %s\n", phrase);

   return 0;
}