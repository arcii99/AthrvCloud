//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function declarations
void generatePassword(int length, char* password);
char getRandomChar();

//Main function
int main()
{
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    char password[length + 1];
    generatePassword(length, password);

    printf("\nYour secure password is: %s", password);

    return 0;
}

//Function to generate password
void generatePassword(int length, char* password)
{
    srand(time(NULL)); // Seed random number generator with current time

    int i;
    for(i=0; i < length; i++)
    {
        password[i] = getRandomChar();
    }

    password[length] = '\0'; // Add terminator character to the end of the string
}

//Function to get a random character
char getRandomChar()
{
    char randomChar;

    //Randomly choose between lowercase, uppercase, and special characters
    int randomChoice = rand() % 3;
    switch(randomChoice)
    {
        case 0:
            //Generate a random lowercase letter (ASCII values 97-122)
            randomChar = (char)(rand() % 26 + 97);
            break;

        case 1:
            //Generate a random uppercase letter (ASCII values 65-90)
            randomChar = (char)(rand() % 26 + 65);
            break;

        case 2:
            //Generate a random special character (ASCII values 33-47 and 58-64)
            int randomSpecial = rand() % 22;
            if(randomSpecial >= 14)
            {
                //Add 8 to the special character to skip the ASCII values 48-57 (numbers)
                randomSpecial += 8;
            }
            randomChar = (char)(randomSpecial + 33);
            break;
    }

    return randomChar;
}