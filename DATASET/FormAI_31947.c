//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int key = 7; //set the encryption key to 7
    int numToEncrypt;
    printf("Please enter the number you would like to encrypt: ");
    scanf("%d", &numToEncrypt);

    int encryptedNum = numToEncrypt * key; //multiply the number by the encryption key
    printf("Your encrypted number is: %d\n", encryptedNum);

    int numToDecrypt;
    printf("Please enter the number you would like to decrypt: ");
    scanf("%d", &numToDecrypt);

    int decryptedNum = numToDecrypt / key; //divide the number by the encryption key to decrypt
    printf("Your decrypted number is: %d\n", decryptedNum);

    return 0;
}