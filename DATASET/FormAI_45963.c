//FormAI DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>

char* encrypt(char* str) {
   int i;
   for(i = 0; i < strlen(str); i++){
       if(i == 0){
            *(str+i) = ((*(str+i)+4)^4);
       } else {
            *(str+i) = ((*(str+i)+4)^*(str+i-1));
       }
   }
   return str;
}

char* decrypt(char* str) {
   int i;
   for(i = strlen(str)-1; i >= 0; i--){
       if(i == 0){
            *(str+i) = ((*(str+i)^4)-4);
       } else {
            *(str+i) = ((*(str+i-1))^*(str+i)-4);
       }
   }
   return str;
}

int main()
{
    printf("Welcome to the C String Encryption/Decryption program!\n\n");

    char original[1000];
    printf("Please enter a message to encrypt: ");
    scanf("%[^\n]s", original);

    char encrypted[1000];
    strcpy(encrypted, encrypt(original));
    printf("Encrypted message: %s\n", encrypted);

    char decrypted[1000];
    strcpy(decrypted, decrypt(encrypted));
    printf("Decrypted message: %s\n", decrypted);

    printf("\nThank you for using our program!");
    return 0;
}