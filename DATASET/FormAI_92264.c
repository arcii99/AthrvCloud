//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char message[100], encrypted[100], decrypted[100];
    int key[100], i, j, choice;
    
    printf("Enter a message to encrypt:");
    fgets(message, sizeof(message), stdin);
    
    // Generate a random key
    for(i = 0; i < sizeof(message); i++)
    {
        key[i] = rand() % 10;
    }
    
    // Encryption
    for(i = 0; i < sizeof(message); i++)
    {
        if(message[i] != '\0')
        {
            encrypted[i] = message[i] + key[i];
        }
        else
        {
            encrypted[i] = '\0';
            break;
        }
    }
    
    printf("Encrypted message: %s\n\n", encrypted);
    printf("Enter 1 to decrypt the message or 2 to exit:");
    scanf("%d", &choice);
    
    while(choice != 2)
    {
        // Decryption
        if(choice == 1)
        {
            for(i = 0; i < sizeof(message); i++)
            {
                if(encrypted[i] != '\0')
                {
                    decrypted[i] = encrypted[i] - key[i];
                }
                else
                {
                    decrypted[i] = '\0';
                    break;
                }
            }
            
            printf("Decrypted message: %s\n\n", decrypted);
        }
        else
        {
            printf("Invalid choice. Please enter 1 to decrypt the message or 2 to exit.\n");
        }
        
        printf("Enter 1 to decrypt the message or 2 to exit:");
        scanf("%d", &choice);
    }
    
    return 0;
}