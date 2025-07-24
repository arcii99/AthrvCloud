//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 23

void encrypt(char *str) {
    int len=strlen(str);
    int i;
    for(i=0; i<len; i++) {
        str[i]=str[i] + KEY; // add the key to the character
    }
}

void decrypt(char *str) {
    int len=strlen(str);
    int i;
    for(i=0; i<len; i++) {
        str[i]=str[i] - KEY; // subtract the key from the character
    }
}

int main() {
    char message[100];
    int choice;
    printf("Enter a message: ");
    scanf("%[^\n]%*c", message);
    printf("Enter your choice: \n");
    printf("1. Encrypt \n");
    printf("2. Decrypt \n");
    scanf("%d", &choice);
  
    switch(choice) {
       case 1:
           encrypt(message);
           printf("Encrypted message: %s\n", message);
           break;
       case 2:
           decrypt(message);
           printf("Decrypted message: %s\n", message);
           break;
       default:
           printf("Invalid Choice!\n");
    }
    return 0;
}