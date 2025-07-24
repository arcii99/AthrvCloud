//FormAI DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int key = 5;
    int i;
    
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    
    for(i = 0; message[i] != '\0'; i++)
    {
        message[i] = (char)(((int)message[i] + key - 97) % 26 + 97);
    }
    
    printf("Encrypted message: %s", message);
    
    return 0;
}