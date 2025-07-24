//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int i,j,n,m;
    printf("Enter the length of message: ");
    scanf("%d",&n);
    getchar();
    printf("Enter the message: ");
    char message[n+2],cipher[n+2];
    for(i=1;i<=n;i++)
    {
        scanf("%c",&message[i]);
    }
    printf("Enter a key for encryption: ");
    char key[n+2];
    for(i=1;i<=n;i++)
    {
        scanf("%c",&key[i]);
    }
    printf("Original message: %s\n",message+1);
    printf("Key: %s\n",key+1);
    printf("Encrypting...\n");
    for(i=1;i<=n;i++)
    {
        cipher[i]=message[i]^key[i];
    }
    cipher[n+1]='\0';
    printf("Encrypted message: %s\n",cipher+1);
    printf("Decrypting...\n");
    for(i=1;i<=n;i++)
    {
        message[i]=cipher[i]^key[i];
    }
    message[n+1]='\0';
    printf("Decrypted message: %s\n",message+1);
    return 0;
}