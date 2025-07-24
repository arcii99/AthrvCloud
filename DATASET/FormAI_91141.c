//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    char message[100], letter;
    int key, i;
    
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    
    printf("Enter a key (1-26): ");
    scanf("%d", &key);
    
    for(i = 0; message[i] != '\0'; ++i)
    {
        letter = message[i];
        
        if(letter >= 'a' && letter <= 'z')
        {
            letter = letter + key;
            
            if(letter > 'z')
            {
                letter = letter - 'z' + 'a' - 1;
            }
            
            message[i] = letter;
        }
        else if(letter >= 'A' && letter <= 'Z')
        {
            letter = letter + key;
            
            if(letter > 'Z')
            {
                letter = letter - 'Z' + 'A' - 1;
            }
            
            message[i] = letter;
        }
    }
    
    printf("Encrypted message: %s", message);
    
    return 0;
}