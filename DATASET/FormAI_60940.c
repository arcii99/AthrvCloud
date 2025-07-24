//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Function to encrypt message using Caesar cipher
char* caesarCipher(char* message, int shift)
{
    int i;
    char ch;
    for(i = 0; i < strlen(message); ++i){
        ch = message[i];
        // Encrypt only letter characters
        if(ch >= 'a' && ch <= 'z'){
            ch = (char)(((int)ch + shift - 97) % 26 + 97);
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = (char)(((int)ch + shift - 65) % 26 + 65);
        }
        message[i] = ch;
    }
    return message;
}

int main()
{
    char message[100], key[100];
    int choice, shift;

    // Menu driven program for user interaction
    while(1){
        printf("\nEnter your choice:\n");
        printf("1. Encrypt message using Caesar Cipher\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("\nEnter message to encrypt: ");
                    scanf(" %[^\n]%*c", message);
                    printf("Enter key (shift): ");
                    scanf("%d", &shift);
                    printf("Encrypted message: %s\n", caesarCipher(message, shift));
                    break;
            case 2: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}