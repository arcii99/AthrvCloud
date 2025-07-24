//FormAI DATASET v1.0 Category: Modern Encryption ; Style: creative
#include<stdio.h>
#include<string.h>

//Function to encrypt the entered message
void encrypt(char message[])
{
    int i, key = 3; //Key value set to 3 for encryption
    int length = strlen(message); //Length of the entered message
    char encrypted[length]; //Variable to store the encrypted message
    
    for(i=0;i<length;i++)
    {
        //If the entered character is uppercase
        if(message[i]>='A' && message[i]<='Z')
            encrypted[i] = (char)(((int)message[i]+key-65)%26 + 65); //Encrypting uppercase character
        
        //If the entered character is lowercase
        else if(message[i]>='a' && message[i]<='z')
            encrypted[i] = (char)(((int)message[i]+key-97)%26 + 97); //Encrypting lowercase character
        
        //If the entered character is a space
        else if(message[i] == ' ')
            encrypted[i] = ' '; //Space remains the same
        
        //If the entered character is any other special character
        else
            encrypted[i] = message[i]; //Special character remains the same
    }
    encrypted[i] = '\0'; //End the encrypted message with null terminator
    
    printf("\nEncrypted Message: %s",encrypted); //Display the encrypted message
}

int main()
{
    char message[100]; //Variable to store the entered message
    
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]%*c", &message); //Scan the entered message until a newline character is encountered
    
    printf("Entered Message: %s",message); //Display the entered message
    
    encrypt(message); //Call the function to encrypt the entered message
    
    return 0;
}