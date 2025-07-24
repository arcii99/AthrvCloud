//FormAI DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include<stdio.h>
#include<string.h>

char * encrypt(char message[]); //function to encrypt the message
char * decrypt(char encrypted[]); //function to decrypt the encrypted message

int main()
{
    char message[100], encrypted[100], decrypted[100]; //defining variables
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); //taking user input

    strcpy(encrypted, encrypt(message)); //copying encrypted message to new variable
    printf("Encrypted message: %s\n", encrypted); //displaying encrypted message

    strcpy(decrypted, decrypt(encrypted)); //copying decrypted message to new variable
    printf("Decrypted message: %s\n", decrypted); //displaying decrypted message

    return 0;
}

char * encrypt(char message[])
{
    int i, key = 13; //defining encryption key value
    char temp;

    for(i = 0; message[i]!='\0'; i++) //iterating through each character in message
    {
        temp = message[i]; //storing the current character in a temp variable 
        if(temp >= 'a' && temp <= 'z') //checking if character is a lowercase letter
        {
            temp = temp + key; //adding key value to temp variable
            if(temp > 'z') //if temp variable goes past 'z'
            {
                temp = temp - 'z' + 'a' - 1; //wrap back to the beginning of the alphabet
            }
            message[i] = temp; //replacing character in message with encrypted character
        }
        else if(temp >= 'A' && temp <= 'Z') //checking if character is an uppercase letter
        {
            temp = temp + key; //adding key value to temp variable
            if(temp > 'Z') //if temp variable goes past 'Z'
            {
                temp = temp - 'Z' + 'A' - 1; //wrap back to the beginning of the alphabet
            }
            message[i] = temp; //replacing character in message with encrypted character
        }
    }

    return message; //returning the encrypted message
}

char * decrypt(char encrypted[])
{
    int i, key = 13; //defining decryption key value
    char temp;

    for(i = 0; encrypted[i]!='\0'; i++) //iterating through each character in encrypted message
    {
        temp = encrypted[i]; //storing the current character in a temp variable 
        if(temp >= 'a' && temp <= 'z') //checking if character is a lowercase letter
        {
            temp = temp - key; //subtracting key value from temp variable
            if(temp < 'a') //if temp variable goes past 'a'
            {
                temp = temp + 'z' - 'a' + 1; //wrap back to the end of the alphabet
            }
            encrypted[i] = temp; //replacing character in encrypted message with decrypted character
        }
        else if(temp >= 'A' && temp <= 'Z') //checking if character is an uppercase letter
        {
            temp = temp - key; //subtracting key value from temp variable
            if(temp < 'A') //if temp variable goes past 'A'
            {
                temp = temp + 'Z' - 'A' + 1; //wrap back to the end of the alphabet
            }
            encrypted[i] = temp; //replacing character in encrypted message with decrypted character
        }
    }

    return encrypted; //returning the decrypted message
}