//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int PUBLIC_KEY = 17;
const int PRIVATE_KEY = 5;

int encrypt(int message)
{
    return ((message * PUBLIC_KEY) % 26);
}

int decrypt(int message)
{
    return ((message * PRIVATE_KEY) % 26);
}

int main()
{
    int message;
    printf("Enter message to encrypt: ");
    scanf("%d", &message);

    int encrypted_message = encrypt(message);
    printf("Encrypted message: %d\n", encrypted_message);

    int decrypted_message = decrypt(encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}