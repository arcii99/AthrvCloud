//FormAI DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    char key[100];
    int i, j = 0, k;
    
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    
    // Remove new lines from input strings
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    // Encrypt the message
    for(i = 0; i < strlen(message); i++)
    {
        if(j == strlen(key))
        {
            j = 0;
        }
        
        k = (message[i] + key[j]) % 26;
        message[i] = k + 'A';
        
        j++;
    }
    
    printf("Encrypted message: %s\n", message);
    
    return 0;
}