//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
#include<stdio.h>
#include<string.h>

int main()
{
    char plaintext[100],ciphertext[100];
    int key=5;
    printf("Enter the text to be encrypted (max 100 characters): ");
    fgets(plaintext, sizeof(plaintext), stdin);

    int n = strlen(plaintext);
    for(int i=0;i<n;i++)
    {
        if(plaintext[i] >= 'a' && plaintext[i] <= 'z')
            ciphertext[i] = (((plaintext[i] - 'a') + key) % 26) + 'a';
        else if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            ciphertext[i] = (((plaintext[i] - 'A') + key) % 26) + 'A';
        else
            ciphertext[i] = plaintext[i];
    }
    ciphertext[n] = '\0';

    printf("\nEncrypted text (Medieval style): ");
    for(int i=0;i<n;i++)
    {
        if(ciphertext[i] == ' ')
            printf("%c",ciphertext[i]);
        else if((ciphertext[i] >= 'a' && ciphertext[i] <= 'm') || (ciphertext[i] >= 'A' && ciphertext[i] <= 'M'))
            printf("%c", 219);
        else if((ciphertext[i] >= 'n' && ciphertext[i] <= 'z') || (ciphertext[i] >= 'N' && ciphertext[i] <= 'Z'))
            printf("%c", 187);
    }
    printf("\n");
    return 0;
}