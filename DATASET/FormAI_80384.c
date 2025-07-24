//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform encryption operation
void encrypt(char* message, int key)
{
    char cipher[MAX_SIZE];
    int i;
    for(i=0;message[i]!='\0';i++)
    {
        //Shift by key and replace characters
        if(message[i]>='a' && message[i]<='z')
        {
            cipher[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
        else if(message[i]>='A' && message[i]<='Z')
        {
            cipher[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
        else
        {
            cipher[i] = message[i];
        }
    }
    //print the encrypted message
    printf("\nEncrypted Message: %s", cipher);
}

int main()
{
    char message[MAX_SIZE];
    int key;
    printf("Enter message to encrypt: ");
    //read the message from user input
    fgets(message, MAX_SIZE, stdin);
    printf("Enter key (1-25): ");
    scanf("%d", &key);
    //perform encryption operation
    encrypt(message, key);
    return 0;
}