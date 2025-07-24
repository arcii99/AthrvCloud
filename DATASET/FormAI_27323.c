//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: futuristic
#include <stdio.h>

// unique public key algorithm implementation
int main()
{
    printf("Welcome to the Future Public Key Algorithm Implementation Program\n");

    // generate key pair
    int public_key = 65537;     // 2^16 + 1 
    int private_key = 132217;   // 3^4 * 271, secret prime factorization

    printf("Public Key: %d\n", public_key);
    printf("Private Key: %d\n", private_key);

    // encryption
    printf("Enter message to encrypt: \n");
    char message[100];
    scanf("%[^\n]", message);   // read until newline
    int i;
    for (i=0; message[i]!='\0'; i++) {
        int char_code = (int) message[i];
        int encrypted_code = char_code * public_key % 999999;   // max value for encryption, 6 digit number
        printf("%d ", encrypted_code);
    }

    // decryption
    printf("\nEnter message to decrypt: \n");
    int encrypted_message[100];
    i = 0;
    while (1) {
        int num;
        scanf("%d", &num);
        if (feof(stdin)) break;   // stop scanning after EOF
        encrypted_message[i++] = num;
    }
    int j, decrypted_code;
    for (j=0; j<i; j++) {
        decrypted_code = encrypted_message[j] * private_key % 999999;   // max value for encryption, 6 digit number
        printf("%c", (char) decrypted_code);
    }

    printf("\nThank you for using the Future Public Key Algorithm Implementation Program\n");

    return 0;
}