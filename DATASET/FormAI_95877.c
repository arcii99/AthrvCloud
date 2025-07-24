//FormAI DATASET v1.0 Category: Modern Encryption ; Style: active
#include<stdio.h>
#include<string.h>

// Function to encrypt the message
void morseEncrypt(char message[], char encryptedMessage[])
{
    // Morse code dictionary
    char morseCode[36][6] = { {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {".----"}, {"..---"}, {"...--"}, {"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}, {"-----"} };
    
    // Length of the message
    int len = strlen(message);
    
    // Iterate through each character of the message
    for(int i=0; i<len; i++)
    {
        // If the character is a space
        if(message[i] == ' ')
            strcat(encryptedMessage, " / ");
                
        // If the character is a letter        
        for(int j=0; j<26; j++)
        {
            if(message[i] == 'A' + j || message[i] == 'a' + j)
                strcat(encryptedMessage, morseCode[j]);
        }
        
        // If the character is a digit
        for(int j=0; j<10; j++)
        {
            if(message[i] == '0' + j)
                strcat(encryptedMessage, morseCode[j+26]);
        }        
    }    
}

int main()
{
    char message[100], encryptedMessage[500] = "";
    
    printf("Enter the message to be encrypted: ");
    gets(message);
    
    // Encrypt the message using Morse code encryption
    morseEncrypt(message, encryptedMessage);
    
    printf("\nEncrypted Message: %s", encryptedMessage);
    
    return 0;
}