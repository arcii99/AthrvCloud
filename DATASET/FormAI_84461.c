//FormAI DATASET v1.0 Category: File Encyptor ; Style: careful
#include<stdio.h>

void encrypt(char []); // function to encrypt the string
void decrypt(char []); // function to decrypt the encrypted string

int main(){
   char text[100];
   int choice;
   printf("Enter the text to encrypt : ");
   fgets(text, sizeof(text), stdin); // read the input string from user

   printf("\nEnter 1 to encrypt and 2 to decrypt the text : ");
   scanf("%d", &choice);

   switch(choice){
      case 1:
            printf("Encrypted text : ");
            encrypt(text);
            break;
      case 2:
            printf("Decrypted text : ");
            decrypt(text);
            break;
      default:
            printf("Invalid option selected!");
   }
   
   return 0;
}

void encrypt(char text[]){
   int i = 0;
   while(text[i] != '\0'){
      text[i] = text[i] + 3; // add 3 to each character of the string 
      i++;
   }
   printf("%s", text); // print the encrypted string
}

void decrypt(char text[]){
   int i = 0;
   while(text[i] != '\0'){
      text[i] = text[i] - 3; // subtract 3 from each character of encrypted string
      i++;
   }
   printf("%s", text); // print the decrypted string
}