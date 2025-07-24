//FormAI DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main()
{
    char password[15] = "CyberPunk2077"; // The password to be decrypted
    char decrypted[15]; // The decrypted password will be stored here
    int i, key = 10; // A key value for decryption

    printf("Enter the password: ");
    scanf("%s", password);

    // Decrypting the password
    for(i = 0; i < strlen(password); i++)
    {
        decrypted[i] = password[i] - key;
    }

    printf("The decrypted password is: %s\n", decrypted);

    return 0;
}